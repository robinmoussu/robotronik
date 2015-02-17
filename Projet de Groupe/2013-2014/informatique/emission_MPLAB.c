/* 
 * File:   main.c
 * Author: medjo
 *
 * Created on 15 mars 2014, 00:43
 */

/*UART sur Patte 18 du PIC => RP9
PWM1H2 (Porteuse) sur Patte 23 (RB12)du PIC*/

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <p33FJ128MC202.h>
#include <libpic30.h>

#define FCY 1000000UL /*FCY est à 1MHz*/
#define BAUDRATE 10UL
#define BRGVAL ((FCY/BAUDRATE)/16)-1


void	init(void)
{
	TRISB = 0 ;// Tous les bits du port A fonctionnennt en sortie (TRISA = 1 pour qu'ils fonctionnent en entrée)
}

void	allumer_diode (void)
{
	_RB12 = 1 ;//Le bit 0 du port A prend la valeur 1
}

void	eteindre_diode (void)
{
	_RB12 = 0 ;//Le bit 0 du port A prend la valeur 0
}

void    emission_porteuse()
{
    while (1)
    {
        allumer_diode() ;
        __delay_us(25) ;
        eteindre_diode() ;
        __delay_us(25) ;
    }
}

void    configure_UART()
{
    _STSEL = 0;/*Stop Selection bit : 1 Stop bit*/
    _PDSEL = 0 ;/*8-bit data, no parity*/
    _ABAUD = 0 ;/*Auto-Baud Disabled*/
    _BRGH = 0 ;/*Low-speed mode*/

    U1BRG = BRGVAL ;/*BAUD Rate Setting for 10*/

    _UARTEN = 1 ;/*UARTx is enabled; all UARTx pins are controlled by UARTx as defined by UEN<1:0>*/
    _UTXEN = 1 ;/*Transmit enabled, UxTX pin controlled by UARTx*/
    _RP9R = 0b00011; /*U1TX is Assigned to RP9 Output Pin bits*/

}

int     main(int argc, char** argv)
{
    init() ;
    configure_UART() ;
    emission_porteuse() ;
    U1TXREG = 0b00000000 ;/*Transmit Data*/
    return (EXIT_SUCCESS);
}

