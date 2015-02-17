
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


/** \file ordonnanceur.h
 * \brief Contient les fonctions relatives à l’ordonnancement
 * 
 * Un timer sur 32 bits permet de mesurer le temps. La granularité est d’environ 300 micro-secondes,
 * et le timer ne déborde qu’au bout de 10 minutes, ce qui est très largement suffisant pour un match
 * (qui dure 90 secondes).
 *
 * Le timer remis à 0 lors du démarage du PIC.
 *
 * \note À plusieurs reprises, le code fait référence à des instructions "timés". Je n’avais pas trouvé de mot aproprié
 * pour signifier « devant s’éxécuter à un moment donné ».
 *  - opnt = operation not timed
 *  - opt  = operation timed
 */

#ifndef ORDONNANCEUR_H
#define ORDONNANCEUR_H

#include <limits.h>

#include "common.h"

/// Nombre maximum d’instructions simultanées devant s’exécuter au bout d’un certain temps (inclue les watchdog)
#define NB_TIMED_INSTRUCTIONS       /*32*/ 1

/// Nombre maximum d’instructions simultanées à exécuter dès que possible (mais de priorités inférieures aux instructions "timés")
#define NB_NOT_TIMED_INSTRUCTIONS   /*16*/ 1



typedef int32_t     Time;
/// Valeur courante du timer
extern Time TIMER;

/// nombre maximum du compteur
#define T_MAX INT_MAX

// Pour un des tests fournis, on manipule des ints, c'est plus simple
#ifndef TEST_INT


struct Op_context;      ///< Les informations utilisées par l'ordonnanceur pour chacune des fonctions
typedef void (*Operation) (struct Op_context *context);    /// < Pointeur vers une fonction à exécuter. Prend en paramètre un pointeur sur le contexte de la fonction.
struct _Op_context {
    Operation op;       ///< la prochaine fonction à exécuter
    void        *args;  ///< un pointeur vers les arguments à passer à la fonction
    Time        t_next;  ///< le moment auquel l'instruction doit être réveillé si necessaire. Si t_next = 0, la prochaine opération n'est pas timé
};
typedef struct _Op_context Op_context;

#else // TEST_INT

typedef int Op_context;

#endif // TEST_INT


/** \brief Exécute les fonctions dans l'ordre prévu
 *  Les opérations devant être exécutées à un moment donné sont prioritaires, puis les autres opérations sont exécutées.
 *  À chaque tour de boucle, on cherche à exécuter une opération timé, et uniquement si il n'y en a
 *  pas, on exécute la prochaine opération non timé.
 * 
 *  \param opt_context  La liste des opérations devant avoir lieu à un moment donné (t = time)
 *  \param opnt_context Les autres opérations (nt = not timed)
 */
void ordonnanceur(Op_context  *opt_context  [NB_TIMED_INSTRUCTIONS], Op_context  *opnt_context [NB_NOT_TIMED_INSTRUCTIONS]);

/** Pointeur sur les fonctions à exécuter
 * \param ops Tableau contenant les différentes fonctions
 */
Op_context* opt_next_op (Op_context **ops, int nb_ops);

/** Initialise les opérations à effectuer
 */
void opt_init (Op_context  *opt_context  [NB_TIMED_INSTRUCTIONS]);

/** Regroupe toutes les opérations dans le début du tableau (pour optimisation)
 */
void op_sort (Op_context **ops, int nb_ops);

/** Ajoute une opération au tableau d'opération
 * \return true si l'opération s'est bien passé, false si il n'y a plus de place
 */
Bool op_add (Op_context **ops, int nb_ops, Op_context *op_new);

/** Efface une opération du tableau d'opération
 */
void op_delete (Op_context *ops[], int nb_ops, Op_context *op_delete);

#endif /* ORDONNANCEUR_H */