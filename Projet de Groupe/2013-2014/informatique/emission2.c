/* 
 * File:   main.c
 * Author: medjo
 *
 * Created on 15 mars 2014, 00:43
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <p33FJ128MC202.h>
#define NB_1_MICROSEC 0x00000001 /*Nombre de cycle d'horloge par microsecondes*/

_FOSCSEL(FNOSC_FRC) ;//Fosc = 7,37 MHz donc Fcy = 3,685 MHz

void	init(void)
{
	TRISA = 0 ;// Tous les bits du port A fonctionnennt en sortie (TRISA = 1 pour qu'ils fonctionnent en entrée)
}

void    configure_32bit_timer()
{
    T2CONbits.T32 = 1 ; //Les timers 2 et 3 sont couplés pour former un timer sur 32 bits
    T2CONbits.TCKPS = 0b00 ; //Fcy est divisé par 1 donc le Timer est incrémenté tous les 271,37 ns
    T2CONbits.TCS = 0b0 ;
    T2CONbits.TGATE = 0b0 ;
    PR2 = 0x0001 ;// défini à 1 la
    PR3 = 0x0000 ;// durée d'une période
    T2CONbits.TON = 1 ;
}

void    delay_microsec(int nb_microsec)
{
    while((TMR3&TMR2) < NB_1_MICROSEC * nb_microsec)
    {
    }
}

void	allumer_diode (void)
{
	_RA0 = 1 ;//Le bit 0 du port A prend la valeur 1
}

void	eteindre_diode (void)
{
	_RA0 = 0 ;//Le bit 0 du port A prend la valeur 0
}

void    emission_porteuse()
{
    while (1)
    {
        allumer_diode() ;
        delay_microsec(26) ;
        eteindre_diode() ;
        delay_microsec(26) ;

    }
}

int     main(int argc, char** argv)
{
    init() ;
    configure_32bit_timer();


    return (EXIT_SUCCESS);
}


