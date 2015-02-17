#include "help_main.h"

int xNousDep;
int yNousDep;
int xNousArr;
int yNousArr;
int xAdv;
int yAdv;
int longPlusChemin;
int longueur;
#ifdef DEUX_ROBOT_ADV
int xAdv2;
int yAdv2;
#endif

Point list = NULL;
Coor chemin = NULL;

void init_main()
{
	init();
	list = loadPointList();
	initToDo();
	initToToDo();
}

void boucle()
{
    if ( toDo.complet == 0b01 )
    {
        xNousDep = toDo.xNousDep;
        yNousDep = toDo.yNousDep;
        xNousArr = toDo.xNousArr;
        yNousArr = toDo.yNousArr;
        xAdv = toDo.xAdv;
        yAdv = toDo.yAdv;
        longPlusChemin = toDo.chemin;

        loadAdversaire(xAdv,yAdv,list);
        chemin = aStar(xNousDep,yNousDep,xNousArr,yNousArr,list);
        longueur = calculLongueur(chemin);

        sendCoor(chemin,calculLongueur(chemin), longPlusChemin);

        initToDo();
        my_free();
        
        #ifndef SIMU
        LATBbits.LATB5 = 1;//debug LED eteinte
        #endif
    }
}
