#ifndef CALCUL_POSITION_H
#define CALCUL_POSITION_H

#include "reception.h"

/** "Lisse les capteurs"
 * Chaque tableau de type Bool nous informe sur l'état des capteurs en prenant en compte que
 * l'une des trois balises émetrices, autrement dit chaque balise est detectée séparement des autres. 
 * Si plusieurs bits d'un capteur sont actifs en même temps (ce qui signifie que la 
 * même balise est détectée plusieurs fois), alors, il faut qu'il n'en reste plus qu'un.
 * \param etat_capteur Le tableau de bits correspondant aux capteurs actifs
 * \param position Position de la tourelle (la moyenne de la position des capteurs)
 */

int lissage(Bool etat_capteur[]);

/** calcule l'angle entre deux capteurs actifs
 *  Après lissage des états des capteurs, on a que 3 capteurs actifs qui sont pris en compte ( 1 capteur pour chaque balise ).
 *  Etant donné que l'angle entre deux capteurs quelconques placés sur le robot est connu ( n*(Pi/8) ) , on détermine l'angle
 *  entre deux capteurs actifs de la tourelle réceptrice. 
 * \param e_1  Le tableau des états de capteurs de la dectection de la balise 1 
 * \param e_2 Le tableau des états de capteurs de la détection de la balise 2
 * \retour la valeur de l'angle entre les deux capteurs actifs. 
 */
float angle( Bool e_1[], Bool e_2[] );

/** calcul l'angle BAR 
 *  Dans la methode de triangulation qu'on utilise pour determiner la position du robot, on a besoin de déterminer la valeur 
 *  de cet angle dont l'expression est tirée à partir du calcul trigonométrique. 
 * \param teta voir image
 * \param alpha voir image
 * \param gamma  voir image
 * \param d longeur de la table du jeu 
 * \param l largeur de la table du jeu 
 * \retour valeur de l'angle BAR
 **/
 
float calcul_bar(float teta, float alpha , float gama, float d ,float l);

/** calcule l'abscisse de la position du robot 
 * l'expression de l'abscisse est déterminée en s'appyant sur la méthode de trianguation et des angles alpha, beta, gamma, BAR déja calculé 
 * \param teta voir image
 * \param alpha voir image
 * \param gamma  voir image
 * \param beta  voir image
 * \param l largeur de la table du jeu 
 * \param bar voir image 
 **/

float abscisse(float alpha ,float beta ,float gama, float l, float bar );

/** calcule l'ordonnée de la position du robot 
 
 * \param teta voir image
 * \param alpha voir image
 * \param gamma  voir image
 * \param beta  voir image
 * \param l largeur de la table du jeu 
 * \param bar voir image 
 **/


float ordonnee(float alpha ,float beta ,float gama, float l, float bar );

/** calcule la position du robot 
 * Au vu des différenet paramétres determinés par les fonctions précedentes , on calcule la position du robot adverse ( X,Y) 
 * sur la table du jeu qui sera ensuite communiqué à notre robot 
 * \param e_1  Le tableau des états de capteurs de la dectection de la balise 1 
 * \param e_2 Le tableau des états de capteurs de la détection de la balise 2
 * \param e_3 Le tableau des états de capteurs de la détection de la balise 3
 * \param d longeur de la table du jeu 
 * \param l largeur de la table du jeu 
 **/
 
 
void calcul_coordonnees(Bool e_1[], Bool e_2[], Bool e_3[], float l,float d);



#endif /* CALCUL_POSITION_H */

