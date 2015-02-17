#include "Carto.h"
#include <SDL/SDL.h>

#include "affich.h"



int main(int argc, char* argv[])
{
    //printf("hello");
    openSDL();

    Point list = NULL;
    ListeSegment segList = NULL;
    /*
    addPoint(&list,350,100,CARRE,10);
    addPoint(&list,400,370,CARRE,10);
    addPoint(&list,500,300,ROND,32);
    addPoint(&list,90,140,ROND,9);
    addPoint(&list,50,40,CARRE,30);
    addPoint(&list,200,320,CARRE,40);
    addPoint(&list,60,250,CARRE,40);
    addPoint(&list,360,200,CARRE,50);
    addPoint(&list,520,60,ROND,12);
    addPoint(&list,200,200,CARRE,20);
*/
    //list = genererPointObstacleTable();
    list = genererPointObstacleRand(10);
    printf("nb de points : %d\n",nbPoint(list));
    //afficherListePoint(list);


    //on creer les segments où le robot peut passer
    segList = creerListeSegment(list);


    drawListePoint(list);

    printf("nb de segments : %d\n",nbSeg(segList));
    //afficherListeSegment(segList);


    //segList = suppSeg(segList,9);

    //les segments  sont trié par ordre croissant
    //tri(segList);
    //printf("trier : \n\n\n");
    //afficherListeSegment(segList);
    //drawListeSegment(segList,0,255,0);//vert



    printf("supp : \n\n\n");

    //suppresion des segments qui se croisent
    segList = suppX(segList);


    //afficherListeSegment(segList);
    drawListeSegment(segList,255,0,0);//rouge
    printf("%d\n",nbSeg(segList));

    Point listPassage;
    listPassage = genererPointPassage(segList);
    drawListePoint(listPassage);

    pause();

    suppListePoint(list);
    suppListeSegment(segList);

    return 0;
}

