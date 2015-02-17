
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



/** \file test_calcul.c
 * \brief Permet de vérifier le calcul de la position
 *
 * Calcule la position du robot. L’état des capteurs est déterminé à l’avance.
 * Ce test permet de vérifier que la position calculée est bien la position rééle du robot.
 */



#include <stdio.h>
#include <math.h>
#include "reception.h"
#include "calcul_position.h"
#define Pi 3,14
#define L 2
#define D 3


Time        TIMER; // TODO a réécrire par Ojeme !
 const Trame trame1;
 const Trame trame2;
 const Trame trame3;
 int main()
{
    Bool tourelle_1[NB_CAPTEUR];
    Bool tourelle_2[NB_CAPTEUR];
    Bool tourelle_3[NB_CAPTEUR];

    tourelle_1[0]= 0;
    tourelle_1[1] = 0;
    tourelle_1[2] = 0;
    tourelle_1[3] = 0;
    tourelle_1[4] = 1;
    tourelle_1[5] =1;
    tourelle_1[6] = 1;
    tourelle_1[7] = 0;
    tourelle_1[8] = 0;
    tourelle_1[9] = 0;
    tourelle_1[10]= 0;
    tourelle_1[11]= 0;
    tourelle_1[12]= 0;
    tourelle_1[13]= 0;
    tourelle_1[14]= 0;
    tourelle_1[15]= 0;

    tourelle_2[0] = 0;
    tourelle_2[1] = 0;
    tourelle_2[2] = 0;
    tourelle_2[3] = 0;
    tourelle_2[4] = 0;
    tourelle_2[5] = 0;
    tourelle_2[6] = 0;
    tourelle_2[7] = 0;
    tourelle_2[8] = 0;
    tourelle_2[9] = 1;
    tourelle_2[10] = 1;
    tourelle_2[11] = 1;
    tourelle_2[12] = 1;
    tourelle_2[13] = 0;
    tourelle_2[14] = 0;
    tourelle_2[15] = 0;

    tourelle_3[0] = 0;
    tourelle_3[1] = 0;
    tourelle_3[2] = 0;
    tourelle_3[3] = 0;
    tourelle_3[4] = 0;
    tourelle_3[5] = 1;
    tourelle_3[6] =1;
    tourelle_3[7] = 1;
    tourelle_3[8] = 1;
    tourelle_3[9] =0;
    tourelle_3[10] = 0;
    tourelle_3[11] = 0;
    tourelle_3[12] = 0;
    tourelle_3[13] = 0;
    tourelle_3[14] = 0;
    tourelle_3[15] = 0;

  calcul_angle(tourelle_1,tourelle_2,tourelle_3,L,D);
  
	}

