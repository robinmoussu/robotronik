#ifndef DOCUMENTATION_H
#define DOCUMENTATION_H


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


/** \mainpage Localisation de robot
 *
 * \section intro_sec Introduction
 *
 * Ce projet à pour but de suivre en temps réél la position d’un robot sur une table de 3×4m environ.
 *
 * \section install_sec Installation
 *
 * \subsection install_subsc Téléchargement des sources
 *
 * Outils necessaires :
 * - svn
 *
 * Éxécutez la commande suivante :

 \verbatim
 svn checkout http://robotronik.googlecode.com/svn/trunk/ robotronik-read-only
 \endverbatim

 *
 * \subsection running_sec Éxécuter le programme
 *
 * Outils necessaires :
 * - mplabx
 * - xc16
 *
 * Des fichiers de projet correspondant à l’émission et la récéption sont fournis. Vous pouvez les ouvrirs avec mplab.
 *
 *
 * \section organisation_sec Organisation du code
 *
 * Le code est organisé de la manière suivante :
 *  - common.h contient les données communes à l’emmition et à la reception
 *  - emission.h contient tout ce qui est relatif à l’emmition
 *  - reception.h contient la machine à état qui gère la reception
 *  - ordonnanceur.h contient tout ce qui est relatif à l’ordonancement des taches de la machine à états
 *
 * Le main (fonction principale) de l’emission et de la réception sont situés respectivement dans :
 *  - emission.c
 *  - main_reception.c
 * 
 * Différents fichiers de tests sont également fournis :
 *  - test_calcul.c
 *  - test_ordonnanceur.c
 *  - test_reception.c
 *
 *
 * \section autor_sec Auteurs
 *
 * Les auteurs de ce programmes commandé par le club Robotronik de Phelma sont :
 *  - Robin Moussu
 *  - Ojeme Iqalo
 *  - Wafa Ben Hadj Sghaier
 *  - Nicolas Lorier
 *  - Rania Berrazaga
 *
 * 
 * \section copyright_sec Copyright and License
 *
 * Ce logiciel est distribué sous la licence GNU GPL v3.

\verbatim

Tracking location of robot
Copyright (C) 2014 Robotronik

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

\endverbatim

 *
 */

#endif /* DOCUMENTATION_H */
