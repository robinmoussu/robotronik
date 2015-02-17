#ifndef CARTO_H_INCLUDED
#define CARTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAILLE_ROBOT 300

#define PRECISION_SQRT 1E-6

#define SQRT2 1.4142
#define INV_SQRT2 0.7071

#define WIDTH_MM  3000
#define HEIGHT_MM 2000

enum _Forme {ROND,CARRE,BORDUREH, BORDUREV};
typedef enum _Forme Forme;


struct Point
{
    int x ;
    int y ;
    Forme f;
    int rayon;
    struct Point* queue;
};

typedef struct Point* Point;

struct ListeSegment
{
    Point a;
    Point b;
    unsigned long lengthSq;
    struct ListeSegment* queue;
};

typedef struct ListeSegment* ListeSegment;


//math
unsigned long carre(unsigned long x);
double sqrt( double x);
double sqrt_aux( double x,  double last);
double dabs(double x);

// Gestion des listes
void afficherListePoint(Point list);
void addPoint(Point* l, int x,int y, Forme f, int rayon);
void suppListePoint(Point list);

void afficherListeSegment(ListeSegment list);
void addSegment(ListeSegment* l , Point a, Point b);
void suppListeSegment(ListeSegment list);
ListeSegment creerListeSegment(Point list);


void addSegmentExistant(ListeSegment* l , ListeSegment aAjouter);
void addSegmentPassage(ListeSegment* l , Point a, Point b);
void addSegmentPassageExistant(ListeSegment* l , ListeSegment aAjouter);



//tri
ListeSegment tri(ListeSegment list);


//croisements
int testAjouter(ListeSegment segNouv, ListeSegment listSeg);
int testAjouter2Seg(ListeSegment seg1, ListeSegment seg2);
int testX(ListeSegment seg1, ListeSegment seg2);
int ptContactExtrem(ListeSegment seg1, ListeSegment seg2);
int testColinAlpha(ListeSegment seg1, ListeSegment seg2 , int ptContact);
ListeSegment trigSeg(ListeSegment listSeg);

//passage cercle
ListeSegment graphPassage(ListeSegment listSeg, Point obstacles, ListeSegment bordures);
int testAjouterSegPassage(ListeSegment segNouv, ListeSegment listSeg, Point obstacles);
int intersecSegObstacle( ListeSegment segNouv, Point obstacles);
int intersecSegCercle(ListeSegment segNouv, Point obstacle);
Point genererPointPassage(ListeSegment list);

int testBordures(ListeSegment nouveau, ListeSegment bordures);

Point genererPointPassage(ListeSegment list);
Point genererPointObstacleTable();
Point genererPointObstacleRand( int nbPoint);


int nbPoint ( Point list );
int nbSeg ( ListeSegment list );

/*
ListeSegment suppX(ListeSegment list);
void initId( ListeSegment list);
ListeSegment suppSeg(ListeSegment list , int id);*/

#endif // CARTO_H_INCLUDED
