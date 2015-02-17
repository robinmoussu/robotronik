/*
 * File:   calcul_position.c
 * Author: Client
 *
 * Created on 28 mars 2014, 13:49
 */

#include <stdio.h>
#include <stdlib.h>
#include <p33FJ128MC202.h>
#include <math.h>

#include "../reception.h"

#define Pi 3.1415
/*
 *
 */
int main(int argc, char** argv) {
    return (EXIT_SUCCESS);
}
int lissage(Etat_capteur e)
{
	int tab[3] = {0,1,2};
	static int i = 0;
    return tab[i++];
}

float angle( Etat_capteur e_1,Etat_capteur e_2 )
{int a, b ;
a=lissage(e_1);
b=lissage(e_2);
return(Pi*b-Pi*a);
}

float  calcul_bar(float teta, float alpha , float gamma ,float d ,float l)
{float a ;
a=sin(alpha)*((d*cos(teta-gamma)-l*sin(gamma))/(d*sin(teta-gamma)+l*tan(alpha)*sin(gamma)));
return( atan(a) );
}


float abscisse(float alpha ,float beta ,float gamma, float l, float bar )
 {
//return l*(sin(bar)^2)*((1/tan(alpha))+(1/tan(bar)));
 }
float ordonnee(float alpha ,float beta ,float gamma, float l, float bar )
 {
//return l*(sin(bar)^2)*(1-(1/tan(alpha))*(1/tan(bar)));
 }


void calcul_angle(Etat_capteur e_1,Etat_capteur e_2,Etat_capteur e_3,float l,float d)
{float teta,alpha , beta , gamma,X,bar;
float x,y;

 alpha=angle(e_1,e_2);
 beta=angle(e_2,e_3);
 gamma=2*Pi-angle(e_1,e_3);
 bar =calcul_bar(teta,alpha,gamma,l,d);
// x = abscisse(alpha, beta, gamma,l,bar);
// y = ordonnee(alpha, beta, gamma,l,bar);
 //send_xbee(x);
 //send_xbee(y);
}