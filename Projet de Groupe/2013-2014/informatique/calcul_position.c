
/*il faut verifier si Pi ( 3,14...) existe sur le pic ou pas , sinon il faut la d�finir )*/

#include <stdio.h>
#include "calcul_position.h"
#include <math.h>
#define Pi 3.14

int lissage(Bool etat_capteur[]) // cette fonction permet de determiner la moyenne de la position de capteur activés sur un nombre de capteur qui ont reçu le sigbal
{
    int i ;
    int S=0 ;
    int n=0 ;
    for(i=0;i<NB_CAPTEUR;i++) {
        if (etat_capteur[i]==1) {
            if (i==0) {
                S=S+1;
            }
            else{

            S=S+i;
            n=n+1;
            }
        }
    }
    S=S/n ;
    return S;
}
float angle( Bool e_1[], Bool e_2[] ) 
{
    int a, b ;
    a=lissage(e_1);
    printf("le capteur actif du tableau 1 est %d \n",a);
    b=lissage(e_2);
    printf("le capteur actif du tableau 2 est %d \n",b);
    return((1.0/8)*(Pi*b-Pi*a));
	

}
float calcul_bar(float teta, float alpha , float gama, float d ,float l) // bar est un angle necessaire au calcul des coordonné de la position -> voir scéma de la table
{
    float a ;
    a=sin(alpha)*((d*cos(teta-gama)-l*sin(gama))/(d*sin(teta-gama)+l*tan(alpha)*sin(gama)));
    return( atan(a) );
}

float abscisse(float alpha ,float beta ,float gama, float l, float bar ) //
{
    return (l*(sin(bar)*sin(bar))*((1/fabs(tan(alpha))+(1/fabs(tan(bar))))));
}
float ordonnee(float alpha ,float beta ,float gama, float l, float bar )
{   printf(" essai %f \n",(1-(1/tan(alpha))*(1/tan(bar))));
    printf(" essai2 %f \n",tan(alpha));
    printf(" essai3 %f \n",1/tan(bar));
    return (l*(sin(bar)*sin(bar))*(1-(1/fabs(tan(alpha))*(1/fabs(tan(bar))))));
}
void calcul_coordonnees(Bool e_1[], Bool e_2[], Bool e_3[], float l,float d)/*d est la longueur de la table , l est la largeur de la table*/
{
    float alpha , beta , gama,teta,bar;
    float x,y;
  
    alpha=angle(e_1,e_2) ;
    printf("alpha est %f \n",alpha);
    beta=angle(e_2,e_3);
    printf("beta est %f \n",beta);
    gama=2*Pi-angle(e_1,e_3);
    printf("gama est %f \n",gama);
    teta=atan(l/(2*d));
    printf("testa %f \n",teta);
    bar=calcul_bar(teta,alpha ,gama,d ,l);
    printf("bar est %f \n",bar);
    x = abscisse(alpha, beta, gama,l,bar);
    y = ordonnee(alpha, beta, gama,l,bar);
    printf("l'abscisse est %f \n",x);
    printf("l'ordonnee est %f \n",y);
}


   //send_xbee(x);
 //send_xbee(y);
 


/*int lissage(Bool etat_capteur[])
{
    int i ;
    int S=0 ;
    int n=0 ;
    for(i=0;i<NB_CAPTEUR;i++) {
        if (etat_capteur[i]==1) {
            S=S+i;
            n=n+1;
        }
    }
    S=S/n ;
    return S;
}
 */
 
 