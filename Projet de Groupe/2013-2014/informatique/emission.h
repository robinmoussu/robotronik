
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


/** \file emmission.h
 * \brief Fichier contenant les fonctions relatives à l’emmition
 */

 
#ifndef EMISSION_H
#define EMISSION_H

typedef enum {
    BALISE1,
    BALISE2,
    BALISE3
} Code;

/* prend en parametre un identifiant unique permettant d'identifier l'emmeteur
 * Utilise les fonctions emission_0 et emission_1 pour emmetre les bits de l'identifiant
 * envoie successivement un bit de start, l'id de l'emmeteur et un bit de stop
 */
//void	emission_trame (Trame ti);

/* emmet le codage correspondant à un bit de valeur 0
 */
void emission_0 ();

/* emmet le codage correspondant à un bit de valeur 1
 */
void emission_1 ();

//void emission_bit (Bit	bit); /*prend en paramètre un bit ( O ou 1 ) et émet ce bit à l'aide des fonctions emission_1 et emission_0*/


#endif /* EMISSION_H */
