#include "Carto.h"
#include <SDL/SDL.h>
#include "dijkstra.h"
#include "affich.h"



int main(int argc, char* argv[])
{
    openSDL();

    Point list = NULL;
    Point listPassage = NULL;
    Point pointsBordures = NULL;

    ListeSegment segList = NULL;
    ListeSegment segTrig = NULL;
    ListeSegment segD = NULL;
    ListeSegment bordures = NULL;

    /*Point depart = NULL;
    Point arrive = NULL;*/

    //**##############POINT DEPART / ARRIVE##################**/
    //addPoint(&depart, 1000,50,ROND,TAILLE_ROBOT);
    //drawListePoint(depart);
    //addPoint(&arrive, 2500,1900,ROND,TAILLE_ROBOT);
    //drawListePoint(arrive);

    /**#############GENERATION POINTS OBSTACLES#############**/

    // || Des points pour tester ||
    // \/         en mm          \/
    /*addPoint(&list,1750,500,CARRE,50);
    addPoint(&list,2000,1850,CARRE,50);
    addPoint(&list,2500,1500,ROND,160);
    addPoint(&list,450,700,ROND,50);
    addPoint(&list,250,200,CARRE,150);
    addPoint(&list,1000,1600,CARRE,200);
    addPoint(&list,300,1250,CARRE,200);
    addPoint(&list,1800,1000,CARRE,250);
    addPoint(&list,2600,300,ROND,60);
    addPoint(&list,1000,1000,CARRE,100);*/

    //  en pixel (= ne plus utiliser)
    /*addPoint(&list,350,100,CARRE,10);
    addPoint(&list,400,370,CARRE,10);
    addPoint(&list,500,300,ROND,32);
    addPoint(&list,90,140,ROND,10);
    addPoint(&list,50,40,CARRE,30);
    addPoint(&list,200,320,CARRE,40);
    addPoint(&list,60,250,CARRE,40);
    addPoint(&list,360,200,CARRE,50);
    addPoint(&list,520,60,ROND,12);
    addPoint(&list,200,200,CARRE,20);*/

    // ||  Une genre de table  ||
    // \/                      \/
    addPoint(&list, 1100,1000  ,CARRE, 125);
    addPoint(&list, 1900, 1000 ,CARRE, 125);
    addPoint(&list, 1500, 1000 ,CARRE, 20);
    //addPoint(&list, 0, 1500 ,ROND, 20);
    //addPoint(&list, 50, 1500 ,CARRE, 20);
    //addPoint(&list, 100, 1500 ,CARRE, 20);
    //addPoint(&list, 150, 1500 ,CARRE, 20);
    //addPoint(&list, 200, 1500 ,CARRE, 20);
    //addPoint(&list, 250, 1500 ,CARRE, 20);
    //addPoint(&list, 300, 1500 ,CARRE, 20);
    //addPoint(&list, 350, 1500 ,CARRE, 20);
    //addPoint(&list, 400, 1500 ,CARRE, 20);
    addPoint(&list, 475, 1525 ,CARRE, 25);
    //addPoint(&list, 500, 1500 ,CARRE, 20);
    addPoint(&list, 2525 , 1525 ,CARRE,25 );
    //addPoint(&list, 2600, 1500 ,CARRE,20 );
    //addPoint(&list, 2700, 1500 ,CARRE, 20);
    //addPoint(&list, 2800, 1500 ,CARRE, 20);
    //addPoint(&list, 2900, 1500 ,CARRE, 20);
    //addPoint(&list, 3000, 1500 ,ROND, 20);
    //addPoint(&list, 2500, 0 ,ROND, 20);

    addPoint(&list, 0,0,CARRE,10);
    addPoint(&list, 0,2000,CARRE,10);
    addPoint(&list, 3000,2000,CARRE,10);
    addPoint(&list, 3000,0,CARRE,10);

    addPoint(&list, 325,0,CARRE,25);
    addPoint(&list, 335,740,CARRE,25);
    addPoint(&list, 2675,0,CARRE,25);
    addPoint(&list, 2665,740,CARRE,25);

    addPoint(&list, 1500,2000,CARRE,25);
    addPoint(&list, 1000,2000,CARRE,25);
    addPoint(&list, 2000,2000,CARRE,25);
    addPoint(&list, 1500,0,CARRE,25);
    addPoint(&list, 1000,0,CARRE,25);
    addPoint(&list, 2000,0,CARRE,25);
    addPoint(&list, 0,1000,CARRE,10);
    addPoint(&list, 3000,1000,CARRE,10);

    addPoint(&list, 2000,1500,CARRE,50);



    /*int i;
    for ( i = 20; i <= 3000 ; i = i + 200)
    {
        //addPoint(&list,i,50,CARRE,60);
        //addPoint(&list,i,1980,CARRE,60);
    }
    for ( i = 200; i < 1900 ; i = i + 400)
    {
        addPoint(&list,20,i,CARRE,60);
        addPoint(&list,2980,i,CARRE,60);
    }*/

    ///rectangles d'obstacles (bordures ...)

    //en haut
    addPoint(&pointsBordures, 0,2000,BORDUREH,0);
    addPoint(&pointsBordures, 3000,2000,BORDUREH,0);

    //en bas
    addPoint(&pointsBordures, 0,0,BORDUREH,0);
    addPoint(&pointsBordures, 3000,0,BORDUREH,0);

    //a gauche
    addPoint(&pointsBordures, 0,2000,BORDUREV,0);
    addPoint(&pointsBordures, 0,0,BORDUREV,0);

    //a droite
    addPoint(&pointsBordures, 3000,0,BORDUREV,0);
    addPoint(&pointsBordures, 3000 ,2000,BORDUREV,0);

    //bordure depart gauche
    addPoint(&pointsBordures, 0,1500,BORDUREH,0);
    addPoint(&pointsBordures, 500,1500,BORDUREH,0);
    addPoint(&pointsBordures, 500,1500,BORDUREV,0);
    addPoint(&pointsBordures, 500,1550,BORDUREV,0);
    addPoint(&pointsBordures, 0,1550,BORDUREH,0);
    addPoint(&pointsBordures, 500,1550,BORDUREH,0);

    //bordure depart droite
    addPoint(&pointsBordures, 2500,1500,BORDUREH,0);
    addPoint(&pointsBordures, 3000,1500,BORDUREH,0);
    addPoint(&pointsBordures, 2500,1500,BORDUREV,0);
    addPoint(&pointsBordures, 2500,1550,BORDUREV,0);
    addPoint(&pointsBordures, 2500,1550,BORDUREH,0);
    addPoint(&pointsBordures, 3000,1550,BORDUREH,0);

    //bordure cale gauche
    addPoint(&pointsBordures, 325,0,BORDUREV,0);
    addPoint(&pointsBordures, 335,740,BORDUREV,0); //coordonées à rectifier

    //bordure cale droite
    addPoint(&pointsBordures, 2675,0,BORDUREV,0);
    addPoint(&pointsBordures, 2665,740,BORDUREV,0);


    //pointsBordures doit avoir un nombre PAIRE de points
    Point it1 = NULL ,it2 =NULL;
    while(pointsBordures != NULL)
    {
        it1 = pointsBordures;
        pointsBordures= pointsBordures->queue;
        it2 = pointsBordures;

        addSegment(&bordures,it1,it2);///longueur² calculer inutilement (à modif) idem carto:intersecSegRect()

        pointsBordures = pointsBordures->queue;
    }


    //drawListePoint(pointsBordures);
    drawListeSegment(bordures,0,0,255);

    //list = genererPointObstacleTable();
    //list = genererPointObstacleRand(10);

    afficherListePoint(list);


    /**##################ALGO################**/
    drawListePoint(list);
    segList = creerListeSegment(list);//on creer les segments **barrer**où le robot peut passer**barrer**
    tri(segList);//les segments  sont triés par ordre croissant
    segTrig = trigSeg(segList);//on triangule ces segments (on les ajoute un par un en verifient qu'il n'en croise pas d'autres)


    listPassage = genererPointPassage(segTrig); // on créer les points de passages a partir des segment trianguler + on elimine les points ds un intervalle trop petits
    drawListePointPassage(listPassage);
    segD = genererSegmentPassage(listPassage);//idem creerListeSegment() mais en utilisant addSegmentpassage()
    ///NOTE: maintenant addSegment() et addSegmentPassage() sont strictement identiques puisque il n'y a plus de filtre sur addSegment()
    /// => creerListeSegment() <=> genererSegmentPassage()
    tri(segD);
    segD = graphPassage(segD,list,bordures);//idem trigSeg() mais en verifient en plus que les segments ne coupent pas un obstacle ( intersecSegObstacle() )
    //                                                                                                                               ^
    //                                                                                                             marche pas  : ----|
    //raccorderDepart(depart,se)


    /**#############AFFICHAGE SDL################**/
    drawListePoint(list);
    //drawListeSegment(segList,0,100,0);
    drawListePointPassage(listPassage);
    //drawListeSegment(segTrig,255,0,0);
    drawListeSegment(segD,0,255,0);


    /**###############AFFICHAGE###############*/
    printf("nb de points d'obstables : %d\n",nbPoint(list));
    printf("nb de segments total (obstacles) : %d\n",nbSeg(segList));
    printf("nb de segments triangule (obstacles) : %d\n",nbSeg(segTrig));
    printf("nb de segments de passage possible : %d\n",nbSeg(segD));


    //afficherListePoint(list);
    //afficherListeSegment(segList);
    //afficherListeSegment(segTrig);
    //afficherListePoint(listPassage);


    //printf("%lf\n",sqrt(142));

    printf("int : %d\n", sizeof(int));
    printf("long : %d\n", sizeof(long));
    printf("float : %d\n", sizeof(float));
    printf("double : %d\n", sizeof(double));
    printf("long double : %d\n", sizeof(long double));

    pause();

    /**#################SUPPRESSION LISTES###############**/
    suppListePoint(list);
    suppListeSegment(segList);
    suppListeSegment(segTrig);
    suppListePoint(listPassage);
    suppListeSegment(segD);

    return 0;
}
