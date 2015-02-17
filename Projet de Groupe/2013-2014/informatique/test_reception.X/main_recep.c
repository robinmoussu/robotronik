/* 
 * File:   main_recep.c
 * Author: medjo
 *
 * Created on 18 avril 2014, 14:26
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <p33FJ128MC802.h>

int main(int argc, char** argv)
{
    _TRISA0 = 0 ;
    _TRISB2 = 1 ;
    _TRISB3 = 1 ;
    _TRISB14 = 0 ;
    while (1)
    {
        _RB14 = 1 ;
        if( _RB2 == 1 || _RB3 == 1 )
        {
            _RA0 = 1 ;
        }
    }
    return (EXIT_SUCCESS);
}

