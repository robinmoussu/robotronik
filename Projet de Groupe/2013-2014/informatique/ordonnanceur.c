// C/C++ File
// AUTHOR:   robin_arch
// FILE:     ordonnanceur.c
// ROLE:     TODO (some explanation)
// CREATED:  2014-03-31 09:49:19
// MODIFIED: 2014-04-11 16:58:57


#include "ordonnanceur.h"



#ifndef TEST

void ordonnanceur(Op_context  *opt_context  [NB_TIMED_INSTRUCTIONS], Op_context  *opnt_context [NB_NOT_TIMED_INSTRUCTIONS])
{
    Op_context  *opt_next;  /// < La prochaine opération ayant lieu à un moment donné (celle ayant le champ t_next le plus petit dans opt_context)
    int         opnt_next;  /// < L'indice de la prochaine opération non timé à exécuter

    opt_next = opt_next_op(opt_context, NB_TIMED_INSTRUCTIONS);
    opt_next = 0;

    while(1){
        if ((opt_next != NULL) && (opt_next->t_next > get_time())) {
            opt_next->op((struct Op_context*) opt_next); // on exécute la prochaine opération
            if (!(opt_next->t_next)) { // on vérifie que la prochaine opération est une opération timé.
                op_delete (opt_context, NB_TIMED_INSTRUCTIONS, (Op_context*) &opt_next);
                op_add(opnt_context, NB_NOT_TIMED_INSTRUCTIONS, (Op_context*) &op_delete);
            }
            // on calcule la nouvelle opération timé
            opt_next = opt_next_op(opt_context, NB_TIMED_INSTRUCTIONS);
        } else {
            // les opérations ne devant pas avoir lieu à un temps donné sont non prioritaires
            if (opnt_context[opnt_next]) {
                opnt_context[opnt_next]->op((struct Op_context*) opnt_context[opnt_next]);
                opnt_next ++;
            } else {
                opnt_next = 0;
            }
        }
    }
}

Op_context* opt_next_op (Op_context **ops, int nb_ops)
{
    int        i;
    Time       t_min;
    Op_context *op_next = NULL;

    for (t_min = T_MAX, i=0; i < nb_ops; i++) {
        if ((ops[i]) && (t_min > ops[i]->t_next)) {
            t_min = ops[i]->t_next;
            op_next = ops[i];
        }
    }

    return op_next;
}
#endif // TEST

void op_sort (Op_context **ops, int nb_ops)
{
    int i;
    int i_free = 0;

    for (i = 0; i < nb_ops; i++) {
        if (ops[i]) {
            ops[i_free++] = ops[i];
        }
    }

    // le tableau est trié, mais il reste des adresses non remise à NULL à la fin du tableau.
    for (i=i_free; i<nb_ops ; i++) {
        ops[i] = NULL;
    }
}

Bool op_add (Op_context **ops, int nb_ops, Op_context *op_new)
{
    int i;

    for (i = 0; i < nb_ops; i++) {
        if (!(ops[i])) {
            ops[i] = op_new;
            return true;
        }
    }

    return false;
}

void op_delete (Op_context *ops[], int nb_ops, Op_context *op_delete)
{
    int i;
    for(i=0;i<nb_ops;i++) {
        if (&(*op_delete) == ops[i]) {
            ops[i] = NULL;
            break;
        }
    }

    op_sort (ops, nb_ops);
}
