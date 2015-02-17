#include "reception.h"
#include "common.h"

void check_bit_start(Op_context *this_operation)
{
    Capteur_state *c = this_operation->args;
    Bit b = get_capteur(c->id_capteur);

    if (b == BIT_START) {

        c->t1 = true;
        c->t2 = true;
        c->t3 = true;
        c->bit_num = 0;

        this_operation->op     = (Operation) check_bit;
        this_operation->t_next = get_time() + (3*DUREE_BIT_MS)/2;
        c->watchdog->t_next    = get_time() + DUREE_WATCHDOG;
    } else {
        this_operation->op     = (Operation) check_bit_start;
        this_operation->t_next = 0; // La prochaine opération n'est pas timé
    }
}

void check_bit(Op_context *this_operation)
{
    Capteur_state *c = this_operation->args;
    Bit b = get_capteur(c->id_capteur);

    c->bit_num++;

    if (trame1[c->bit_num] != b) {
        c->t1 = false;
        c->tourelle_1[c->id_capteur] = false;
    }
    if (trame2[c->bit_num] != b) {
        c->t2 = false;
        c->tourelle_2[c->id_capteur] = false;
    }
    if (trame3[c->bit_num] != b) {
        c->t3 = false;
        c->tourelle_3[c->id_capteur] = false;
    }

    if (c->t1 || c->t2 || c->t3) {
        this_operation->t_next    += (3*DUREE_BIT_MS)/2;
        c->watchdog->t_next        = get_time() + DUREE_WATCHDOG;
        if (c->bit_num < NB_BIT) {
            this_operation->op     = (Operation) check_bit;
        } else {
            this_operation->op     = (Operation) check_bit_stop;
        }
    } else {
        this_operation->op      = (Operation) check_bit_start;
        this_operation->t_next += DUREE_ATTENTE_MS;
    }
}

void check_bit_stop(Op_context *this_operation)
{
    Capteur_state *c = this_operation->args;
    Bit b = get_capteur(c->id_capteur);

    c->bit_num++;

    if (b == BIT_STOP) {
        c->tourelle_1[c->id_capteur] = c->t1;
        c->tourelle_2[c->id_capteur] = c->t2;
        c->tourelle_3[c->id_capteur] = c->t3;

        this_operation->op      = (Operation) check_bit;
        this_operation->t_next += (3*DUREE_BIT_MS)/2;
        c->watchdog->t_next     = get_time() + DUREE_WATCHDOG;
    } else {
        c->tourelle_1[c->id_capteur] = false;
        c->tourelle_2[c->id_capteur] = false;
        c->tourelle_3[c->id_capteur] = false;

        this_operation->op      = (Operation) check_bit_start;
        this_operation->t_next += DUREE_ATTENTE_MS;
    }
}

void clear_watchdog(Op_context *this_operation)
{
    Capteur_state *c = this_operation->args;

    c->tourelle_1[c->id_capteur] = false;
    c->tourelle_2[c->id_capteur] = false;
    c->tourelle_3[c->id_capteur] = false;

    this_operation->t_next       = get_time() + DUREE_WATCHDOG;
}

Bool get_capteur(int num_capteur)
{
    switch(num_capteur) {
        case 0 : return _RA4 ;
        case 1 : return _RB4 ;
        case 2 : return _RA3 ;
        case 3 : return _RA2 ;
        case 4 : return _RA0 ;
        case 5 : return _RA1 ;
        case 6 : return _RB2 ;
        case 7 : return _RB3 ;
        case 8 : return _RB15 ;
        case 9 : return _RB14 ;
        case 10 : return _RB13 ;
        case 11 : return _RB12 ;
        case 12 : return _RB8 ;
        case 13 : return _RB9 ;
        case 14 : return _RB10 ;
        case 15 : return _RB11 ;
        default : return false; // ce cas est impossible, c'est juste pour éviter un warning
    }
}
 
