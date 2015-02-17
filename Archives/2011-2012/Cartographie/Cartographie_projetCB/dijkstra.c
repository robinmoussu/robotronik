#include "dijkstra.h"

/*
 -creer N
 -creer Q ( Q =copie N)
 -intitialisation infini
 -maj distance noeud
 -trouve min
 -ajouter precedent
 -supp celui ké min
 -maj
 - ...
 */

void addNoeud(Noeud* n, int id ,int x, int y,int distance, int precedent)
{
    Noeud nouveau = malloc(sizeof(struct Noeud));
    nouveau->id = id;
    nouveau->x = x;
    nouveau->y = y;
    nouveau->distance = distance;
    nouveau->precedent = precedent;

    nouveau->queue = *n;
    *n = nouveau;
}

void suppNoeud(Point list)
{
    Point buff;
    while(list != NULL)
    {
        buff = list->queue;
        free(list);
        list = buff;
    }
}

 void creerN( ListeSegment S , Noeud N )
 {
    int i;

    /*en construction*/
    while ( S != NULL )
    {
        addNoeud(&N, i, S->a->x,S->a->y, INFINI, -1);

        i++;
        S=S->queue;
    }



     return N;
 }

 int testNoeud( int x, int y , Noeud N)
 {
     while ( N != NULL )
    {
        if ( x == N->x)
        {

        }
        N=N->queue;
    }
 }

 void creerQ( Noeud N , Noeud Q)
 {

 }

void initialisation( Noeud Q)
{

}

void maj ( Noeud n , Noeud Q, ListeSegment S)
{

}

int trouvemin(Noeud n ,ListeSegment S)
{



    //return id;
}

void suppmin( int id , Noeud Q)
{

}

void dijkstra( ListeSegment S , Point Depart , Point Arrive)
{

    Noeud N = NULL;
    Noeud Q = NULL;

    initialisation(N);

}



