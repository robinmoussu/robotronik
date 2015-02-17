
/*
 *    Tracking location of robot
 *    Copyright (C) 2014 Robotronik
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



/** \file main_reception.c
 * \brief Fichier contenant le main utilisé par la réception.
 */

//#include <p33FJ128MC802.h>
#include "common.h"
#include "reception.h"
#include "ordonnanceur.h"



union Int16_32 {
    unsigned long int all;
    struct {
        unsigned int higher;
        unsigned int lower;
    };
};
typedef union Int16_32 Int16_32;


/** Routine d’initialisation du microcontroleur PIC
 *  \note À exécuter uniquement au début du programme
 *  Initialise les registres des modules utilisés par le PIC dans le projet
 */
void initPic();

/** Initialisation d'un timer sur 32 bit
 *  \note utilise les timers 2 et 3
 */
void init_32bits_timer();

/** Recupere la valeur courante du timer sur 32 bits
 *  \see init_32bits_timer()
 */
unsigned long int get_time();


const Trame trame1; 	///< trame identifiant la tourelle 1
const Trame trame2; 	///< trame identifiant la tourelle 1
const Trame trame3; 	///< trame identifiant la tourelle 1

void test2(Op_context *this_operation);
void test1(Op_context *this_operation)
{
    ////////////////////////
        _RA0 = 0;
        //////////////////////////////:
    this_operation->op     = (Operation) test2;
    this_operation->t_next = get_time() + _1MS;
}
void test2(Op_context *this_operation)
{
    ////////////////////////
        _RA0 = 1;
        //////////////////////////////:
    this_operation->op     = (Operation) test1;
    this_operation->t_next = get_time() + 2*_1MS;
}
void test3(Op_context *this_operation)
{
    ////////////////////////
        _RB14 = !_RB14;
        //////////////////////////////:
}

int main(void)
{

    // les capteurs virtuels correspondant à chaque tourelle
    char tourelle_1 [NB_CAPTEUR];
    char tourelle_2 [NB_CAPTEUR];
    char tourelle_3 [NB_CAPTEUR];

//    // les watchdogs pour remettre les capteur à false au bout d'un certain temps
//    Op_context w1  = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//    Op_context w2  = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//    Op_context w3  = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//    Op_context w4  = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//    Op_context w5  = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//    Op_context w6  = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//    Op_context w7  = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//    Op_context w8  = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//    Op_context w9  = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//    Op_context w10 = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//    Op_context w11 = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//    Op_context w12 = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//    Op_context w13 = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//    Op_context w14 = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//    Op_context w15 = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//    Op_context w16 = {(Operation) clear_watchdog, NULL, DUREE_WATCHDOG};
//
//    // L'état de chaque capteurs
//    Capteur_state c1 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                1,
//                &w1,
//                false, false, false,
//                0
//            };
//    Capteur_state c2 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                2,
//                &w2,
//                false, false, false,
//                0
//            };
//    Capteur_state c3 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                3,
//                &w3,
//                false, false, false,
//                0
//            };
//    Capteur_state c4 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                4,
//                &w4,
//                false, false, false,
//                0
//            };
//    Capteur_state c5 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                5,
//                &w5,
//                false, false, false,
//                0
//            };
//    Capteur_state c6 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                6,
//                &w6,
//                false, false, false,
//                0
//            };
//    Capteur_state c7 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                7,
//                &w7,
//                false, false, false,
//                0
//            };
//    Capteur_state c8 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                8,
//                &w8,
//                false, false, false,
//                0
//            };
//    Capteur_state c9 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                9,
//                &w9,
//                false, false, false,
//                0
//            };
//    Capteur_state c10 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                10,
//                &w10,
//                false, false, false,
//                0
//            };
//    Capteur_state c11 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                11,
//                &w11,
//                false, false, false,
//                0
//            };
//    Capteur_state c12 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                12,
//                &w12,
//                false, false, false,
//                0
//            };
//    Capteur_state c13 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                13,
//                &w13,
//                false, false, false,
//                0
//            };
//    Capteur_state c14 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                14,
//                &w14,
//                false, false, false,
//                0
//            };
//    Capteur_state c15 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                15,
//                &w15,
//                false, false, false,
//                0
//            };
//    Capteur_state c16 = {
//                tourelle_1, tourelle_2, tourelle_3,
//                16,
//                &w16,
//                false, false, false,
//                0
//            };
//
//    Op_context o1  =  {(Operation) check_bit_start, &c1, 0};
//    Op_context o2  =  {(Operation) check_bit_start, &c2, 0};
//    Op_context o3  =  {(Operation) check_bit_start, &c3, 0};
//    Op_context o4  =  {(Operation) check_bit_start, &c4, 0};
//    Op_context o5  =  {(Operation) check_bit_start, &c5, 0};
//    Op_context o6  =  {(Operation) check_bit_start, &c6, 0};
//    Op_context o7  =  {(Operation) check_bit_start, &c7, 0};
//    Op_context o8  =  {(Operation) check_bit_start, &c8, 0};
//    Op_context o9  =  {(Operation) check_bit_start, &c9, 0};
//    Op_context o10  = {(Operation) check_bit_start, &c10, 0};
//    Op_context o11  = {(Operation) check_bit_start, &c11, 0};
//    Op_context o12  = {(Operation) check_bit_start, &c12, 0};
//    Op_context o13  = {(Operation) check_bit_start, &c13, 0};
//    Op_context o14  = {(Operation) check_bit_start, &c14, 0};
//    Op_context o15  = {(Operation) check_bit_start, &c15, 0};
//    Op_context o16  = {(Operation) check_bit_start, &c16, 0};

    //////////////////////////////////
    Op_context test_12  = {(Operation) test1, NULL, _1MS};
    Op_context test_3  = {(Operation) test3, NULL, 0};
    //////////////////////////////////

//    // les tableau contenant les threads
//    Op_context  *opt_context  [NB_TIMED_INSTRUCTIONS] = {
//            &w1 , &w2, &w3, &w4, &w5, &w6, &w7, &w8, &w9, &w10, &w11, &w12, &w13, &w14, &w15, &w16,
//            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
//    };
//    Op_context  *opnt_context [NB_NOT_TIMED_INSTRUCTIONS] = {
//           &o1, &o2, &o3, &o4, &o5, &o6, &o7, &o8, &o9, &o10, &o11, &o12, &o13, &o14, &o15, &o16
//    };

    Op_context  *opt_context  [NB_TIMED_INSTRUCTIONS] = {
            &test_12
    };
    Op_context  *opnt_context [NB_NOT_TIMED_INSTRUCTIONS] = {
            &test_3
    };

    int i;
    unsigned long int last_state ;
    unsigned long int increment;


    initPic() ;

    last_state = 0 ;
    TRISB = 0 ;
    TRISA = 0 ;
    _RA0  = 1 ;
    _RB14 = 1 ;

    increment = F_TICS/1000;

    for (i = 0; i < NB_CAPTEUR; i++) {
        tourelle_1[i] = false;
        tourelle_2[i] = false;
        tourelle_3[i] = false;
    }

//    while(1)
//    {
//        if ((last_state + increment) < get_time())
//        {
//            _RB5 = !_RB5;
//            last_state = last_state + increment;
//        }
//    }
//    return (0) ;

    ordonnanceur(opt_context, opnt_context);
    return 0;
}

void initPic()
{
    init_32bits_timer();
}

void init_32bits_timer()
{
    T2CONbits.T32 = 1 ;/*TMRx and TMRy form a 32-bit timer*/
    T2CONbits.TCKPS = 0 ;/*1:1 prescale value*/
    T2CONbits.TCS = 0 ;/* Internal clock (FOSC/2)*/
    T2CONbits.TGATE = 0 ;/*Gated time accumulation disabled*/
    PR3 = 0xFFFF ;/*Définit les MSB de la période du timer*/
    PR2 = 0xFFFF ;/*Définit les LSB de la période du timer*/
    T2CONbits.TON = 1 ;/*Starts 32-bit TMRx:TMRy timer pair*/
    /*The timer value at any point is stored in the register pair TMR3:TMR2. TMR3 always contains the most significant word of the count, while TMR2 contains the least significant word.*/
    TMR3 = 0;
    TMR2 = 0;
}

unsigned long int get_time() {
    Int16_32 temp;
    temp.lower = TMR3;
    temp.higher = TMR2;
    return temp.all;
};