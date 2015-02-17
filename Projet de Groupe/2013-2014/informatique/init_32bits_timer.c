/* 
 * File:   configure.c
 * Author: medjo
 *
 * Created on 16 mai 2014, 15:25
 */

//#include <libpic30.h>
//#include <xc.h>
#include <p33FJ128MC802.h>

/*
 * 
 */





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

union Int16_32 {
    unsigned long int all;
    struct {
        unsigned int higher;
        unsigned int lower;
    };
};
typedef union Int16_32 Int16_32;

unsigned long int get_time() {
    Int16_32 temp;
    temp.lower = TMR3;
    temp.higher = TMR2;
    return temp.all;
};

#define F_TICS 7370000/2
int main()
{

    unsigned long int last_state ;
    unsigned long int increment;


    init_32bits_timer() ;

    last_state = 0 ;
    TRISB = 0 ;
    _RB14 = 1 ;

    increment = F_TICS/1000;

    while(1)
    {
        if ((last_state + increment) < get_time())
        {
            _RB14 = !_RB14;
            last_state = last_state + increment;
        }
    }
    return (0) ;
}
