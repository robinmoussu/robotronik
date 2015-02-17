
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


/** \file common.h
 * \brief Contient les données communes à l’emission et la réception
 * \note Doit être inclu dans tous les fichiers du projet
 */

#ifndef COMMON_H
#define COMMON_H

#include <p33FJ128MC802.h>

#ifndef Bool
// Compatibilité avec le C89
enum Bool {
    false = 0,
    true  = 1
};
typedef char Bool;
#endif //Bool

#ifndef NULL
#define NULL 0
#endif

/** Valeur des bits constituant une trame
 *
 * Une trame est constitué
 *  - d'un bit de start à 1
 *  - de 8 bits
 *  - d'un bit de stop à zéro
 */
typedef enum {
    BIT_STOP = 0,
    BIT_START = 1,
    BIT_1 = 1,
    BIT_0 = 0
} Bit;

/// Nombre de bits dans une trame
#define NB_BIT 8
typedef Bit Trame[NB_BIT + 2];

// Les trames qui servent d'identificateur unique pour chacune des tourelles
extern const Trame trame1; 	///< trame identifiant la tourelle 1
extern const Trame trame2; 	///< trame identifiant la tourelle 2
extern const Trame trame3; 	///< trame identifiant la tourelle 3

#define F_TICS 7370000/2
#define _1MS (F_TICS)/1000
#define DUREE_BIT_MS 17*(_1MS)      ///< Durée d’un bit en TICs
#define DUREE_ATTENTE_MS 2*(_1MS)   ///< Durée d’attente entre deux trames

unsigned long int get_time();
#endif /* COMMON_H */
