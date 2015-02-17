
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



/** \file test_ordonnanceur.c
 * \brief teste la validitée de l’ordonnanceur.
 *
 * Ce fichier permet de tester les fonction add, delete et sort de l'ordonnanceur.
 * Il utilise des entiers pour faciliter le test
 *
 * \note Doit être compilé avec l'option TEST_INT
 * \note À tester sur pc, avec le compilateur gcc ou clang
 */

#include <stdio.h>
#include "ordonnanceur.h"


void affiche();

// Pour faciliter l'affichage, j'utilise des variables globales
int i = 100;
int j = 200;
int k = 300;

int *ta [3] = {&i,0,0};
int *tb [4] = {&j, &k, 0, 0};
int *p = &i;

int main(void)
{
    printf("Etat initial\n");
    affiche();

    printf("déplacement de i de ta vers tb\n");
    p = &i;
    op_delete (ta, 3, p);
    op_add(tb,4,p);
    affiche();

    printf("déplacement de k de tb vers ta\n");
    p = &k;
    op_add (ta, 3, p);
    op_delete(tb,4,p);
    affiche();

    return 0;
}

void affiche()
{
    int a;

    printf("i=%d j=%d k=%d\n",i,j,k);
    printf("adresse : &i=%p &j=%p &k=%p\n",&i,&j,&k);
    printf("\n");
    printf("pointeur p=%p ",p);
    if(p) {
        printf(" *p=%d &(*p)=%p",*p, &(*p));
    }
    printf("\n");
    printf("\n");
    for (a = 0; a<3; a++) {
        printf("ta[%d] :%p ",a, ta[a]);
        if(ta[a]) {
            printf(" *ta[%d]]%d",*ta[a], a);
        }
        printf("\n");
    }
    printf("\n");
    for (a = 0; a<4; a++) {
        printf("tb[%d] :%p ",a, tb[a]);
        if(tb[a]) {
            printf(" *ta[%d]]%d",*tb[a], a);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}
