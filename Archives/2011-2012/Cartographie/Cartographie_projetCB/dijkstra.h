#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "carto.h"

struct Noeud
{
    int id;
    int x;
    int y;
    int distance;
    int precedent;
    struct Noeud* queue;
};
typedef struct Noeud* Noeud;

void addNoeud(Noeud* n, int id ,int x, int y,int distance, int precedent);
//void maj( Noeud n , Noeud Q, ListeSegment S);
int trouvemin(Noeud n ,ListeSegment S);

#define INFINI -1


#endif // DIJKSTRA_H_INCLUDED
