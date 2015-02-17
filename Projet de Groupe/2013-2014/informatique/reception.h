
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
 

/** \file reception.h
 * \brief Machine à état permettant la reception des trames d’identifications.
 *
 * Voici le fonctionnement d'un capteur sous forme d'une machine à état :
 *  - Attente du bit de start.
 *  - Initialisation de trois Booléens (un par tourelle) à vrai. Cela veux dire que la trame en cours de réception peux correspondre à la l'identifiant de la tourelle.
 *  - Pour chacun des bits
 *     + Attente du bit suivant.
 *     + Pour chaque tourelle
 *         * Si le bit correspond, on ne fait rien.
 *         * Sinon, on met le Booléen correspondant à la tourelle à faux et on signale que la trame reçu est fausse.
 *     + Fin pour
 *     + On recommence la boucle, si au moins un des Booléens correspondant aux tourelles est encore à vrai.
 *     + Sinon, on recommence au début.
 *  - Fin pour
 *  - On vérifie la présence du bit de stop.
 *  - Si toutes les étapes précédantes sont validées, alors on signale que la trame reçu est valide pour la tourelle correspondate (celle ou le Booléen est encore à vrai).
 *
 * Il faut également s'assurer après la reception d'une trame + le temps inter trame que l'on reçoit une nouvelle trame. En cas de non reception, il faut signaler que la trame reçu est fausse.
 *
 */

#ifndef RECEPTION_H
#define RECEPTION_H

#include "common.h"
#include "ordonnanceur.h"

/// Temps avant lequel le watchdog est appelé, et la trame considéré fausse.
#define DUREE_WATCHDOG 10 * (DUREE_BIT_MS)

/// Nombre de capteurs physiques sur le module de réception.
#define NB_CAPTEUR 16

/** Etat interne des capteurs
 * \note Il y doit y avoir NB_CAPTEUR variables Capteur_state (un par capteur)
 */
struct Capteur_state {
    // données constantes
    Bool *tourelle_1;       ///< vrai si la balise 1 est détectée par ce capteur
    Bool *tourelle_2;       ///< vrai si la balise 2 est détectée par ce capteur
    Bool *tourelle_3;       ///< vrai si la balise 3 est détectée par ce capteur
    int id_capteur;         ///< identifiant unique du capteur
    Op_context *watchdog;   ///< pointeur sur la fonction a exécuter si cela fait trop longtemps qu’aucun bit n’est reçu

    // donnée temporaires
    Bool t1;                ///< Vrai si la trame en cour de réception pourrait etre celle de la balise 1
    Bool t2;                ///< Vrai si la trame en cour de réception pourrait etre celle de la balise 2
    Bool t3;                ///< Vrai si la trame en cour de réception pourrait etre celle de la balise 3
    int bit_num;            ///< Numéro du bit de la trame en cour de reception
};
typedef struct Capteur_state Capteur_state;

/** Teste si un bit de start est présent. Si oui, initialise l'état du capteur.
 * \param Capteur_state Etat interne du capteur.
 * \return true si le bit est un bit de start.
 */
void check_bit_start(Op_context *this_operation);

/** Test la validité d'un bit pour chacune des tourelle, et met à jour l'état interne du capteur en conséquence, ainsi que les tableau Etat_capteur en cas de non validité.
 * \param Capteur_state Etat interne du capteur.
 * \return vrai si le bit est valide pour au moins une des tourelle.
 */
void check_bit(Op_context *this_operation);

/** Verifie que le bit de stop est bien présent. Si c'est le cas, met à jour les tableaux Etat_capteur.
 * \param Capteur_state Etat interne du capteur.
 * \return true si le bit était un bit de stop.
 */
void check_bit_stop(Op_context *this_operation);

/** remet à false l'état courant du capteur
 */
void clear_watchdog(Op_context *this_operation);

/** retourne true si le capteur numéro num_capteur détecte un bit à 1
 * \param num_capteur prend les valeurs {0,1,...,15}
 */
Bool get_capteur(int num_capteur);

#endif /* RECEPTION_H */

