#include "Carto.h"



unsigned long carre(unsigned long x)
{
    return (unsigned long)x*x;
}

double sqrt(  double x)
{
    if (x<0)
        return 0;

    return sqrt_aux(x,x);
}

double sqrt_aux(  double x,  double last)
{
    double next;
    next = (last+x/last) / 2;
    if (dabs(next - last) < PRECISION_SQRT)
    {
        return next;
    }
    else
    {
        return sqrt_aux(x, next);
    }

}

double dabs(double x)
{
    if (x<0)
    {
        return -x;
    }
    else
    {
        return x;
    }
}

//points
void afficherListePoint(Point list)
{
    while(list != NULL)
    {
        //printf("%d: ", list->id);
        printf("%d ", list->x);
        printf("%d ", list->y);
        printf("%d ", list->rayon);
        printf("\n");
        list = list->queue;
    }
}

/*
Liste addElement(Liste l, int element)
{
    Liste nouveau = malloc(sizeof(struct Chainon));
        nouveau->value = element;
        nouveau->queue = l;
    return nouveau;
}
*/

void addPoint(Point* l, int x,int y, Forme f, int rayon)
{
    Point nouveau = malloc(sizeof(struct Point));
        nouveau->x = x;
        nouveau->y = y;
        nouveau->f = f;
        nouveau->rayon = rayon;
        nouveau->queue = *l;
    *l = nouveau;
}

void suppListePoint(Point list)
{
    Point buff;
    while(list != NULL)
    {
        buff = list->queue;
        free(list);
        list = buff;
    }
}


//segments

void afficherListeSegment(ListeSegment list)
{
    while(list != NULL)
    {
        //printf("####%d####\n",list->id);
        printf("%d ", list->a->x);
        printf("%d ", list->a->y);
        printf("%d ", list->a->rayon);
        printf("\n");
        printf("%d ", list->b->x);
        printf("%d ", list->b->y);
        printf("%d ", list->b->rayon);
        printf("\n");
        printf("%ld\n ", list->lengthSq);
        printf("\n");
        list = list->queue;
    }
}


void addSegment(ListeSegment* l , Point a, Point b)
{
    unsigned long longueurCarre = ( carre((a->x - b->x)) + carre((a->y - b->y)) );
    /*if ( carre(a->rayon + b->rayon + TAILLE_ROBOT) >= longueurCarre )
    {
        return;
    }*/


    ListeSegment nouveau = malloc(sizeof(struct ListeSegment));
        nouveau->a = a;
        nouveau->b = b;
        nouveau->lengthSq = longueurCarre;
        nouveau->queue = *l;
    *l = nouveau;
}
void addSegmentExistant(ListeSegment* l , ListeSegment aAjouter)//cette fct evite de recalculer lengthsq inutilement
{
    ListeSegment nouveau = malloc(sizeof(struct ListeSegment));
        nouveau->a = aAjouter->a;
        nouveau->b = aAjouter->b;
        nouveau->lengthSq = aAjouter->lengthSq;
        nouveau->queue = *l;
    *l = nouveau;
}

void addSegmentPassage(ListeSegment* l , Point a, Point b)
{
     unsigned long longueurCarre = ( carre((a->x - b->x)) + carre((a->y - b->y)) );
     ListeSegment nouveau = malloc(sizeof(struct ListeSegment));
        nouveau->a = a;
        nouveau->b = b;
        nouveau->lengthSq = longueurCarre;
        nouveau->queue = *l;
    *l = nouveau;
}
void addSegmentPassageExistant(ListeSegment* l , ListeSegment aAjouter)
{
     ListeSegment nouveau = malloc(sizeof(struct ListeSegment));
        nouveau->a = aAjouter->a;
        nouveau->b = aAjouter->b;
        nouveau->lengthSq = aAjouter->lengthSq;
        nouveau->queue = *l;
    *l = nouveau;
}


void suppListeSegment(ListeSegment list)
{
    ListeSegment buff;
    while(list != NULL)
    {
        buff = list->queue;
        free(list);
        list = buff;
    }
}

ListeSegment creerListeSegment(Point list)
{
    ListeSegment segList =NULL;
    Point it1 = NULL ,it2 =NULL;
    for (it1 = list; it1 !=NULL; it1 = it1->queue)
    {

        for ( it2=it1->queue ; it2 != NULL ; it2 = it2->queue)
        {
            //if (it1->rayon )
                addSegment(&segList,it1,it2);
                //i++;
        }
        //i++;
    }

    return segList;
}
ListeSegment genererSegmentPassage(Point list)
{
    ListeSegment segList =NULL;
    Point it1 = NULL ,it2 =NULL;
    for (it1 = list; it1 !=NULL; it1 = it1->queue)
    {

        for ( it2=it1->queue ; it2 != NULL ; it2 = it2->queue)
        {
                addSegmentPassage(&segList,it1,it2);
        }

    }

    return segList;
}


ListeSegment tri(ListeSegment list)
{
    ListeSegment it1,it2,min;
    Point auxA,auxB;
    unsigned long auxLength;
    for (it1=list; it1->queue != NULL; it1=it1->queue)
    {
        min=it1;
        for (it2=it1->queue; it2 != NULL; it2=it2->queue)
        {
            if (it2->lengthSq < min->lengthSq)
            min=it2;
        }
        if (min != it1)
        {
            auxLength=min->lengthSq;
            auxA=min->a;
            auxB=min->b;


            min->lengthSq = it1->lengthSq;
            min->a = it1->a;
            min->b = it1->b;


            it1->lengthSq = auxLength;
            it1->a = auxA;
            it1->b = auxB;

        }
    }
    return(list);
}

int testAjouter(ListeSegment segNouv, ListeSegment listSeg)
{

    while (listSeg != NULL)
    {
            if (testAjouter2Seg(segNouv ,listSeg) == 0)
            {
                return 0;//NE PAS AJOUTER, un segment est incompatible
            }
            listSeg=listSeg->queue;
    }
    return 1;//AJOUTER, sinon c'est bon
}

int testAjouter2Seg(ListeSegment seg1, ListeSegment seg2)
{
    if ( testX(seg1, seg2) == 0)
    {
        return 0;//NE PAS AJOUTER
    }
    else if ( testX(seg1, seg2) == 1)
    {
        return 1; //AJOUTER
    }
    else if ( testX(seg1, seg2) == 2)// CAS Colineaire
    {
            int ptContact = ptContactExtrem(seg1,seg2);
            if ( ptContact == 0)
            {
                return 1; //AJOUTER
            }
            else if ( ptContact > 0 )
            {
                if ( testColinAlpha(seg1,seg2,ptContact) == 1)
                {
                    return 1;//AJOUTER càd alpha < 0
                }
                else if ( testColinAlpha(seg1,seg2,ptContact) == 0 )
                {
                    return 0;//NE PAS AOUTER càd alpha >=0
                }

        }
    }
    return -1;//big erreur si ici
}


int testX(ListeSegment seg1, ListeSegment seg2)//renvoi 0 si pas d'intersection, 1 sinon , 2 si colineaire.
{

    int Ax = seg1->a->x;
    int Ay = seg1->a->y;
    int Bx = seg1->b->x;
    int By = seg1->b->y;
    int Cx = seg2->a->x;
    int Cy = seg2->a->y;
    int Dx = seg2->b->x;
    int Dy = seg2->b->y;

    //methode : equations parametriques

    long Ix,Iy,Jx,Jy;
    double m,k;
    Ix = Bx-Ax;
    Iy = By-Ay;
    Jx = Dx-Cx;
    Jy = Dy-Cy;

    if (Ix*Jy-Iy*Jx ==0) // les segments sont parralleles (colineaire)
    {

        return 2;  // retourne 'colineaire'

    }

    m = -(-(double)Ix*Ay+Ix*Cy+Iy*Ax-Iy*Cx)/((double)Ix*Jy-(double)Iy*Jx);
    k = -((double)Ax*Jy-Cx*Jy-Jx*Ay+Jx*Cy)/((double)Ix*Jy-(double)Iy*Jx);

    //printf("%lf  %lf\n",m,k);

    if ( (0<k && k<1) && (0<m && m<1 ))
    {
        //puts("0");
        return 0; //retourne NE PAS AJOUTER il ya intesection
    }
    else
    {
        return 1; //AJOUTER
    }
}

int ptContactExtrem(ListeSegment seg1, ListeSegment seg2)
{
    int Ax = seg1->a->x;
    int Ay = seg1->a->y;
    int Bx = seg1->b->x;
    int By = seg1->b->y;
    int Cx = seg2->a->x;
    int Cy = seg2->a->y;
    int Dx = seg2->b->x;
    int Dy = seg2->b->y;

    if ((Ax == Cx) && (Ay == Cy))
    {
        return 13;
    }
    else if ((Ax == Dx) && (Ay == Dy))
    {
        return 14;
    }
    else if ( (Bx == Cx) && (By == Cy))
    {
        return 23;
    }
    else if ( (Bx == Dx) && (By == Dy))
    {
        return 24;
    }
    else
    {
        return 0;
    }

}

int testColinAlpha(ListeSegment seg1, ListeSegment seg2 , int ptContact)
{
    //le seg2 est forcement plus grand que le seg1
    int Ax = seg1->a->x;
    int Ay = seg1->a->y;
    int Bx = seg1->b->x;
    int By = seg1->b->y;
    int Cx = seg2->a->x;
    int Cy = seg2->a->y;
    int Dx = seg2->b->x;
    int Dy = seg2->b->y;

    double alpha;

    switch (ptContact)
    {
        case 13://A  == C
            if ((Ax == Bx) || (Cx == Dx) )//verticale (une seule condition est necessaire en fait)
            {
                alpha = ((double)Dy-Ay)/(By-Ay);
            }
            else//tous les autres cas
            {
                alpha = (Dx-Ax)/(Bx-Ax);
            }
            break;
        case 14://A  == D
            if ((Ax == Bx) || (Cx == Dx) )//verticale
            {
                alpha = (Cy-Ay)/(By-Ay);
            }
            else
            {
                alpha = (Cx-Ax)/(Bx-Ax);
            }
            break;
        case 23://B  == C
            if ((Ax == Bx) || (Cx == Dx) )//verticale
            {
                alpha = (Dy-By)/(Ay-By);
            }
            else
            {
                alpha = (Dx-Bx)/(Ax-Bx);
            }
            break;
        case 24://B  == D
            if ((Ax == Bx) || (Cx == Dx) )//verticale
            {
                alpha = (Cy-By)/(Ay-By);
            }
            else
            {
                alpha = (Cx-Bx)/(Ax-Bx);
            }
            break;
    }
    //printf("alpha : %lf\n",alpha);
    if (alpha  < 0 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


ListeSegment trigSeg(ListeSegment listSeg)
{

    ListeSegment nouveau = NULL;
    //addSegment(&nouveau, listSeg->a,listSeg->b);//on ajoute le premier (le plus court )
    addSegmentExistant(&nouveau, listSeg);
    //drawListeSegment(nouveau, 255,0,0);
    //pause1();
    while (listSeg != NULL)
    {
        if ( testAjouter(listSeg, nouveau) == 1)
        {
            addSegmentExistant(&nouveau, listSeg);
            //drawListeSegment(nouveau, 255,0,0);
            //pause1();

        }
        listSeg=listSeg->queue;

    }
    return nouveau;
}

ListeSegment graphPassage(ListeSegment listSeg, Point obstacles, ListeSegment bordures)
{
    ListeSegment nouveau = NULL;
    /// SUPPRIME par Anthony :
    //addSegmentPassageExistant(&nouveau, listSeg);
    while (listSeg != NULL)
    {
        //drawListeSegment(nouveau, 0,255,0);
        if ( testAjouterSegPassage(listSeg, nouveau, obstacles) && testBordures(listSeg,bordures))
        {
            addSegmentPassageExistant(&nouveau, listSeg);
            //addSegmentPassage(&nouveau, listSeg->a, listSeg->b);
            //drawListeSegment(nouveau, 0,255,0);
            //pause1();
        }
        listSeg=listSeg->queue;

    }
    return nouveau;
}

/*int testBordures(ListeSegment segNouv, ListeSegment bordures)
{
    //pause1();
    Point A = NULL, B= NULL, C=NULL, D=NULL;
    ListeSegment AB = NULL, BD = NULL, DC =NULL, CA =NULL;
    addPoint(&A, bordures->a->x -TAILLE_ROBOT/2, bordures->a->y - TAILLE_ROBOT/2,BORDURE,0);
    addPoint(&C, bordures->a->x -TAILLE_ROBOT/2, bordures->a->y + TAILLE_ROBOT/2,BORDURE,0);
    addPoint(&B, bordures->b->x +TAILLE_ROBOT/2, bordures->b->y - TAILLE_ROBOT/2,BORDURE,0);
    addPoint(&D, bordures->b->x +TAILLE_ROBOT/2, bordures->b->y + TAILLE_ROBOT/2,BORDURE,0);

    addSegment(&AB, A,B);///calcul inutile de lenght^2 idem main:bordures
    addSegment(&BD, B,D);
    addSegment(&DC, D,C);
    addSegment(&CA, C,A);

    while (bordures != NULL)
    {
        addPoint(&A, bordures->a->x -TAILLE_ROBOT/2, bordures->a->y - TAILLE_ROBOT/2,BORDURE,0);
        addPoint(&C, bordures->a->x -TAILLE_ROBOT/2, bordures->a->y + TAILLE_ROBOT/2,BORDURE,0);
        addPoint(&B, bordures->b->x +TAILLE_ROBOT/2, bordures->b->y - TAILLE_ROBOT/2,BORDURE,0);
        addPoint(&D, bordures->b->x +TAILLE_ROBOT/2, bordures->b->y + TAILLE_ROBOT/2,BORDURE,0);

        addSegment(&AB, A,B);///calcul inutile de lenght^2 idem main:bordures
        addSegment(&BD, B,D);
        addSegment(&DC, D,C);
        addSegment(&CA, C,A);
        if (testX(segNouv, AB)  == 0)
        {
            suppListeSegment(AB);
            suppListeSegment(BD);
            suppListeSegment(DC);
            suppListeSegment(CA);
            suppListePoint(A);
            suppListePoint(B);
            suppListePoint(C);
            suppListePoint(D);
            //puts("BD");
            return 0;
        }
        else if (testX(segNouv, BD)  == 0)
        {
            suppListeSegment(AB);
            suppListeSegment(BD);
            suppListeSegment(DC);
            suppListeSegment(CA);
            suppListePoint(A);
            suppListePoint(B);
            suppListePoint(C);
            suppListePoint(D);
            return 0;
        }
        else if (testX(segNouv, DC)  == 0)
        {
            suppListeSegment(AB);
            suppListeSegment(BD);
            suppListeSegment(DC);
            suppListeSegment(CA);
            suppListePoint(A);
            suppListePoint(B);
            suppListePoint(C);
            suppListePoint(D);
            return 0;
        }
        else if (testX(segNouv, CA)  == 0)
        {
            suppListeSegment(AB);
            suppListeSegment(BD);
            suppListeSegment(DC);
            suppListeSegment(CA);
            suppListePoint(A);
            suppListePoint(B);
            suppListePoint(C);
            suppListePoint(D);
            return 0;
        }
        if (testX(segNouv,bordures) == 0)
        //if (1)
        {
            //puts("0");
            suppListeSegment(AB);
            suppListeSegment(BD);
            suppListeSegment(DC);
            suppListeSegment(CA);
            suppListePoint(A);
            suppListePoint(B);
            suppListePoint(C);
            suppListePoint(D);
            return 0;//intersection
        }

        bordures = bordures->queue;
    }
    suppListeSegment(AB);
    suppListeSegment(BD);
    suppListeSegment(DC);
    suppListeSegment(CA);
    suppListePoint(A);
    suppListePoint(B);
    suppListePoint(C);
    suppListePoint(D);
    return 1;//c'est bon
}*/

int testBordures(ListeSegment segNouv, ListeSegment bordures)
{
    //pause1();
    Point A = NULL, B= NULL, C=NULL, D=NULL;
    ListeSegment AB = NULL, BD = NULL, DC =NULL, CA =NULL;
    while (bordures != NULL)
    {

        if ( bordures->a->f == BORDUREH)
        {
            if ( bordures->a->x < bordures->b->x)
            {
                addPoint(&A, bordures->a->x -TAILLE_ROBOT/2, bordures->a->y + TAILLE_ROBOT/2,BORDUREH,0);
                addPoint(&C, bordures->a->x -TAILLE_ROBOT/2, bordures->a->y - TAILLE_ROBOT/2,BORDUREH,0);
                addPoint(&B, bordures->b->x +TAILLE_ROBOT/2, bordures->b->y + TAILLE_ROBOT/2,BORDUREH,0);
                addPoint(&D, bordures->b->x +TAILLE_ROBOT/2, bordures->b->y - TAILLE_ROBOT/2,BORDUREH,0);
            }
            else
            {
                addPoint(&A, bordures->a->x +TAILLE_ROBOT/2, bordures->a->y + TAILLE_ROBOT/2,BORDUREH,0);
                addPoint(&C, bordures->a->x +TAILLE_ROBOT/2, bordures->a->y - TAILLE_ROBOT/2,BORDUREH,0);
                addPoint(&B, bordures->b->x -TAILLE_ROBOT/2, bordures->b->y + TAILLE_ROBOT/2,BORDUREH,0);
                addPoint(&D, bordures->b->x -TAILLE_ROBOT/2, bordures->b->y - TAILLE_ROBOT/2,BORDUREH,0);
            }
        }
        else
        {
            if ( bordures->a->y < bordures->b->y)
            {
                addPoint(&A, bordures->a->x +TAILLE_ROBOT/2, bordures->a->y - TAILLE_ROBOT/2,BORDUREV,0);
                addPoint(&C, bordures->a->x -TAILLE_ROBOT/2, bordures->a->y - TAILLE_ROBOT/2,BORDUREV,0);
                addPoint(&B, bordures->b->x +TAILLE_ROBOT/2, bordures->b->y + TAILLE_ROBOT/2,BORDUREV,0);
                addPoint(&D, bordures->b->x -TAILLE_ROBOT/2, bordures->b->y + TAILLE_ROBOT/2,BORDUREV,0);
            }
            else
            {
                addPoint(&A, bordures->a->x +TAILLE_ROBOT/2, bordures->a->y + TAILLE_ROBOT/2,BORDUREV,0);
                addPoint(&C, bordures->a->x -TAILLE_ROBOT/2, bordures->a->y + TAILLE_ROBOT/2,BORDUREV,0);
                addPoint(&B, bordures->b->x +TAILLE_ROBOT/2, bordures->b->y - TAILLE_ROBOT/2,BORDUREV,0);
                addPoint(&D, bordures->b->x -TAILLE_ROBOT/2, bordures->b->y - TAILLE_ROBOT/2,BORDUREV,0);
            }
        }
        addSegment(&AB, A,B);///calcul inutile de lenght^2 idem main:bordures
        addSegment(&BD, B,D);
        addSegment(&DC, D,C);
        addSegment(&CA, C,A);

        if (testX(segNouv, AB)  == 0)
        {
            suppListeSegment(AB);
            suppListeSegment(BD);
            suppListeSegment(DC);
            suppListeSegment(CA);
            suppListePoint(A);
            suppListePoint(B);
            suppListePoint(C);
            suppListePoint(D);
            //puts("BD");
            return 0;
        }
        else if (testX(segNouv, BD)  == 0)
        {
            suppListeSegment(AB);
            suppListeSegment(BD);
            suppListeSegment(DC);
            suppListeSegment(CA);
            suppListePoint(A);
            suppListePoint(B);
            suppListePoint(C);
            suppListePoint(D);
            return 0;
        }
        else if (testX(segNouv, DC)  == 0)
        {
            suppListeSegment(AB);
            suppListeSegment(BD);
            suppListeSegment(DC);
            suppListeSegment(CA);
            suppListePoint(A);
            suppListePoint(B);
            suppListePoint(C);
            suppListePoint(D);
            return 0;
        }
        else if (testX(segNouv, CA)  == 0)
        {
            suppListeSegment(AB);
            suppListeSegment(BD);
            suppListeSegment(DC);
            suppListeSegment(CA);
            suppListePoint(A);
            suppListePoint(B);
            suppListePoint(C);
            suppListePoint(D);
            return 0;
        }
        if (testX(segNouv,bordures) == 0)
        {
            //puts("0");
            suppListeSegment(AB);
            suppListeSegment(BD);
            suppListeSegment(DC);
            suppListeSegment(CA);
            suppListePoint(A);
            suppListePoint(B);
            suppListePoint(C);
            suppListePoint(D);
            return 0;//intersection
        }


        bordures = bordures->queue;
    }

    return 1;//c'est bon
}

int testAjouterSegPassage(ListeSegment segNouv, ListeSegment listSeg, Point obstacles)
{

    while (listSeg != NULL)
    {
            if (!testAjouter2Seg(segNouv ,listSeg) || intersecSegObstacle(segNouv, obstacles)) // changement par Anthony
            //if (intersecSegObstacle(segNouv, obstacles))
            {
                return 0;//NE PAS AJOUTER, un segment est incompatible
            }
            listSeg=listSeg->queue;
    }
    return 1;//AJOUTER, sinon c'est bon
}

int intersecSegObstacle( ListeSegment segNouv, Point obstacles)
{
    while ( obstacles != NULL)
    {
        if (obstacles->f == ROND)
        {
            if (intersecSegCercle(segNouv, obstacles) == 1)
            {
                return 1;//il y a intersection

            }
        }
        else
        {
            if (intersecSegRect(segNouv, obstacles))
            {
                return 1;// il y a intersection => pas ajouter
            }
        }


        obstacles = obstacles->queue;
    }
    return 0;//sinon yen a pas eu
}

int intersecSegRect(ListeSegment segNouv, Point obstacle)
{
    //largueur/2 = rayon*(1/sqrt(2))   car rayon = diagonale/2
    //
    //  A __________ B
    //   |          |    |
    //   |     lSur2|    |
    //   |    .-----|    | l
    //   |          |    |
    // C |__________| D  |
    //
    //drawDisque(obstacle->x, obstacle->y,obstacle->rayon+TAILLE_ROBOT/2,200,200,200);
    //drawDisque(obstacle->x, obstacle->y,obstacle->rayon,150,150,150);

    int rayon =  obstacle->rayon + TAILLE_ROBOT/2;
    int lSur2 = rayon*INV_SQRT2, i =0;
    Point A = NULL, B= NULL, C=NULL, D=NULL;
    ListeSegment AB = NULL, BD = NULL, DC =NULL, CA =NULL;

    addPoint(&A,obstacle->x - lSur2, obstacle->y + lSur2, CARRE, 0 );
    addPoint(&B,obstacle->x + lSur2, obstacle->y + lSur2, CARRE, 0 );
    addPoint(&C,obstacle->x - lSur2, obstacle->y - lSur2, CARRE, 0 );
    addPoint(&D,obstacle->x + lSur2, obstacle->y - lSur2, CARRE, 0 );
    /*
    A->x = obstacle->x - lSur2;
    A->y = obstacle->y + lSur2;

    B->x = obstacle->x + lSur2;
    B->y = obstacle->y + lSur2;

    C->x = obstacle->x - lSur2;
    C->y = obstacle->y - lSur2;

    D->x = obstacle->x + lSur2;
    D->y = obstacle->y - lSur2;
    */
    addSegment(&AB, A,B);///calcul inutile de lenght^2 idem main:bordures
    addSegment(&BD, B,D);
    addSegment(&DC, D,C);
    addSegment(&CA, C,A);



    if (testX(segNouv, AB)  == 0)
    {
        suppListeSegment(AB);
        suppListeSegment(BD);
        suppListeSegment(DC);
        suppListeSegment(CA);
        suppListePoint(A);
        suppListePoint(B);
        suppListePoint(C);
        suppListePoint(D);
        //puts("BD");
        return 1;
    }
    else if (testX(segNouv, BD)  == 0)
    {
        suppListeSegment(AB);
        suppListeSegment(BD);
        suppListeSegment(DC);
        suppListeSegment(CA);
        suppListePoint(A);
        suppListePoint(B);
        suppListePoint(C);
        suppListePoint(D);
        return 1;
    }
    else if (testX(segNouv, DC)  == 0)
    {
        suppListeSegment(AB);
        suppListeSegment(BD);
        suppListeSegment(DC);
        suppListeSegment(CA);
        suppListePoint(A);
        suppListePoint(B);
        suppListePoint(C);
        suppListePoint(D);
        return 1;
    }
    else if (testX(segNouv, CA)  == 0)
    {
        suppListeSegment(AB);
        suppListeSegment(BD);
        suppListeSegment(DC);
        suppListeSegment(CA);
        suppListePoint(A);
        suppListePoint(B);
        suppListePoint(C);
        suppListePoint(D);
        return 1;
    }



    suppListeSegment(AB);
    suppListeSegment(BD);
    suppListeSegment(DC);
    suppListeSegment(CA);
    suppListePoint(A);
    suppListePoint(B);
    suppListePoint(C);
    suppListePoint(D);
    //puts("0");
    return 0;


}

/*
int intersecSegCercle(ListeSegment segNouv, Point obstacle)///anciene fonction lourde mais marche moyennement
{
    //*
    int Ax = segNouv->a->x/8;
    int Ay = segNouv->a->y/8;
    int Bx = segNouv->b->x/8;
    int By = segNouv->b->y/8;

    int Ox = Ax - obstacle->x/8;
    int Oy = Ay - obstacle->y/8;

    int r = (obstacle->rayon + TAILLE_ROBOT/2)/8;
    //*/

    /*
    int Ax = segNouv->a->x;
    int Ay = segNouv->a->y;
    int Bx = segNouv->b->x;
    int By = segNouv->b->y;

    int Ox = Ax - obstacle->x;
    int Oy = Ay - obstacle->y;

    int r = obstacle->rayon;
    //*/
/*
    double Ix = Bx-Ax;
    double Iy = By-Ay;
    //printf("Ix= %lf, Iy= %lf\n",Ix,Iy);

    double A, B,C;

    //on resout A*t^2 + B*t + C = 0
    //A=carre(Ix)+carre(Iy);
    A=Ix*Ix+Iy*Iy;
    B=2*(Ix*Ox+Iy*Oy);
    C= carre(Ox)+carre(Oy)-carre(r);
    //printf("A : %lf, B = %lf, C=%lf\n",A,B,C);

    double delta = carre(B) -4*A*C;
    //printf("delta = %lf\n",delta);

    if ( delta < 0)
    {
        //puts("neg");
        return 0;
    }
    else if (delta == 0)
    {
        if (-B/(2*A)>0 && -B/(2*A)<1 )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else // delta >0
    {
        //printf("delta pos : ");
        if (  (-B + sqrt(delta))/(2*A) >0 && (-B + sqrt(delta))/(2*A) <1)
        {
            //printf("1\n");
            return 1;
        }
        else
        {
            //printf("0\n");
            return 0;
        }
    }
}*/

int intersecSegCercle(ListeSegment segNouv, Point obstacle) ///nouvelle fonction plus legere mais ne marche pas pour l'instant
{
    int Ax = segNouv->a->x;
    int Ay = segNouv->a->y;
    int Bx = segNouv->b->x;
    int By = segNouv->b->y;

    int Ox = obstacle->x;
    int Oy = obstacle->y;

    int r = obstacle->rayon;

    int Ux = Bx-Ax;
    int Uy = By-Ay;

    int Vx = Ox-Ax;
    int Vy = Oy-Ay;

    /*Ux /=100;
    Uy /=100;
    Vx /=100;
    Vy /=100;

    r /=100;

    Ox /=100;
    Oy /=100;*/

    // Si l'obstacle est mega loin du segment, inutile de tester :
    int Wx = Ox-Bx;
    int Wy = Oy-By;

    unsigned long test = carre(r + TAILLE_ROBOT/2);

    unsigned long hCarre = carre(Vx)+carre(Vy);
    unsigned long boCarre = carre(Wx)+carre(Wy);
    if(hCarre > test && boCarre > test)
        return 0; // Mega loin, donc ca passe

    unsigned long lCarre = carre(Ux*Vx+Uy*Vy)/(carre(Ux)+carre(Uy)) ;//produit scalaire^2/AB^2

    //int lCarre = carre(l)

    unsigned long xCarre = hCarre - lCarre;// x² = h² - l²
    printf(" x =%u\n",xCarre );

    if ( xCarre > test)
    {
        return 0;//ça passe
    }
    else
    {
        return 1;//ça passe pas
    }



}




int nbPoint ( Point list )
{
    int i = 0;
    while (list != NULL)
     {
         i++;
         list = list->queue;
     }
     return i;

}

int nbSeg ( ListeSegment list )
{
    int i = 0;
    while (list != NULL)
     {
         i++;
         list = list->queue;
     }
     return i;

}


Point genererPointPassage(ListeSegment list)
{
    Point listPassage = NULL;
    //Point listPrime = NULL;

    int Ax,Ay,Bx,By,Arx,Ary,Brx,Bry,test;
    double l;
    double Ix,Iy;
    while (list != NULL)
    {
        Ax=list->a->x;
        Ay=list->a->y;
        Bx=list->b->x;
        By=list->b->y;

        l = sqrt(list->lengthSq);
        test = l- list->a->rayon - list->b->rayon;
        if (test <= TAILLE_ROBOT)
        {
            list = list->queue;//suivant il est trop petit
        }
        else
        {
            Arx = list->a->rayon*(Bx-Ax)/l +Ax;
            Ary = list->a->rayon*(By-Ay)/l +Ay;

            Brx = list->b->rayon*(Ax-Bx)/l +Bx;
            Bry = list->b->rayon*(Ay-By)/l +By;

            Ix = (Arx + Brx )/2;
            Iy = (Ary + Bry )/2;
            addPoint(&listPassage,Ix,Iy,ROND,(test - TAILLE_ROBOT)/2);

            list = list->queue;
        }
        //Ix= ( list->b->rayon*list->a->x + list->a->rayon*list->b->x )/(list->a->rayon + list->b->rayon);
        //Iy= ( list->b->rayon*list->a->y + list->a->rayon*list->b->y )/(list->a->rayon + list->b->rayon);


        /*addPoint(&listPrime,Arx,Ary,ROND,0);
        addPoint(&listPrime,Brx,Bry,ROND,0);*/


    }
    return listPassage;
}

Point genererPointObstacleTable()
{
    Point list = NULL;
    int i;
    for ( i = 10; i < 600 ; i = i + 100)
    {
        addPoint(&list,i,10,ROND,10);
        addPoint(&list,i,390,ROND,10);
    }
    for ( i = 10; i < 400 ; i = i + 100)
    {
        addPoint(&list,10,i,ROND,10);
        addPoint(&list,590,i,ROND,10);
    }
    addPoint(&list,590,390,ROND,10);
    for ( i = 100; i <= 500 ; i = i + 100)
    {
        addPoint(&list,i,100,ROND,10);
        addPoint(&list,i,200,ROND,10);
        addPoint(&list,i,300,ROND,10);

    }

    return list;
}

Point genererPointObstacleRand( int nbPoint)
{
    srand ( time(NULL) );
    Point list = NULL;
    int i=0;
    while ( i < nbPoint)
    {
        addPoint(&list,rand() % 600,rand() % 400,ROND,1);
        i++;
    }
    return list;
}


//inutile
/*
ListeSegment suppX(ListeSegment list)
{

    ListeSegment it1=NULL, it2=NULL;

    for (it1 = list; it1 !=NULL; it1 = it1->queue)
    {
        for ( it2=it1->queue ; it2 != NULL ; it2 = it2->queue)
        {
            if (testX(it1 ,it2) == 1)
            {
                if (it1->lengthSq <= it2->lengthSq)
                {
                    //printf("2 supp\n");
                    list = suppSeg(list, it2->id);
                    list = suppX(list);
                    return list;

                }
                else
                {
                    //printf("1 supp\n");
                    list = suppSeg(list, it1->id);
                    list = suppX(list);
                    return list;
                }
            }
        }
    }
    return list;
}

//inutile
ListeSegment suppSeg(ListeSegment list , int id)
{
    ListeSegment nouveau = NULL;
    while (list != NULL)
    {
        if (list->id != id)
        {
             addSegment(&nouveau,list->a,list->b,list->id);
             list=list->queue;
        }
        else
        {
            free(list);// necessaire ?
            list=list->queue;
        }
    }
    list = nouveau;
    return list;
}
*/
/*
void initId( ListeSegment list)
{
    int i=0;
    while (list != NULL)
    {
        list->id = i;
        i++;
        list = list->queue;

    }
}*/
/*
int intersecSegCercle(ListeSegment segNouv, Point obstacle)
{
    //*
    int Ax = segNouv->a->x/8;
    int Ay = segNouv->a->y/8;
    int Bx = segNouv->b->x/8;
    int By = segNouv->b->y/8;

    int Ox = Ax - obstacle->x/8;
    int Oy = Ay - obstacle->y/8;

    int r = obstacle->rayon/8;
    //*/

    /*
    int Ax = segNouv->a->x;
    int Ay = segNouv->a->y;
    int Bx = segNouv->b->x;
    int By = segNouv->b->y;

    int Ox = Ax - obstacle->x;
    int Oy = Ay - obstacle->y;

    int r = obstacle->rayon;
    //*/

/*
    double Ix = Bx-Ax;
    double Iy = By-Ay;
    //printf("Ix= %lf, Iy= %lf\n",Ix,Iy);

    //double k = -(-Ix*Ay+Ix*Cy+Iy*Ax-Iy*Cx)/(Ix*Jy-Iy*Jx);

    //double B;
    double A, B,C;

    //on resout A*t^2 + B*t + C = 0
    //A=carre(Ix)+carre(Iy);
    A=Ix*Ix+Iy*Iy;
    B=2*(Ix*Ox+Iy*Oy);
    C= carre(Ox)+carre(Oy)-carre(r);
    //printf("A : %lf, B = %lf, C=%lf\n",A,B,C);

    double delta = carre(B) -4*A*C;
    //printf("delta = %lf\n",delta);

    if ( delta < 0)
    {
        //puts("                               neg");
        return 0;
    }
    else if (delta == 0)
    {
        if (-B/(2*A)>0 && -B/(2*A)<1 )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else // delta >0
    {
        //printf("delta pos : ");
        if (  (-B + sqrt(delta))/(2*A) >0 && (-B + sqrt(delta))/(2*A) <1)
        {
            //printf("1\n");
            return 1;
        }
        else
        {
            //printf("0\n");
            return 0;
        }
    }


}*/

/*
int testHV(ListeSegment seg1, ListeSegment seg2)
{
    int Ax = seg1->a->x;
    int Ay = seg1->a->y;
    int Bx = seg1->b->x;
    int By = seg1->b->y;
    int Cx = seg2->a->x;
    int Cy = seg2->a->y;
    int Dx = seg2->b->x;
    int Dy = seg2->b->y;

    if (Ax == Bx && Ax == Dx)
    {
        return 'V';
    }
    else if ( Ay == By && Ay == Dy)
    {
        return 'H';
    }
    else
    {
        return 0;
    }
}
*//*
int testConfondu(ListeSegment seg1, ListeSegment seg2, int valHV)
{

        int Ax = seg1->a->x;
    int Ay = seg1->a->y;
    int Bx = seg1->b->x;
    int By = seg1->b->y;
    int Cx = seg2->a->x;
    int Cy = seg2->a->y;
    int Dx = seg2->b->x;
    int Dy = seg2->b->y;

    if (valHV == 'H')
    {
        if ( Cx > Ax && Dx < Bx)
        {
            puts("confondu");
            return 1;
        }
        else if ( Ax > Cx && Bx < Dx)
        {
            puts("confondu");
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (valHV == 'V')
    {
        if ( Cy > Ay && Dy < By)
        {
            puts("confondu");
            return 1;
        }
        else if ( Ay > Cy && By < Dy)
        {
            puts("confondu");
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        puts("error");
    }


}*/
