#ifndef MALLOC_H_INCLUDED
#define MALLOC_H_INCLUDED

#include "config_carto.h"


#ifndef SIMU
#include <p33FJ128MC802.h>
#endif

/*
Le tas heap est remplit par les fonctions addPoint() et addListeFils(),
gr�ce � my_malloc(), il ne peut �tre lib�r�, my_free() est inutile.
Le tas 2 heap2 est remplit par addSet(), addData(), addCame() et addCoor(),
gr�ce � my_malloc2(), il est lib�r� par my_free() qui "efface"
TOUTES les allocations, c�d toutes les listes Set, Data, ...
*/

#define NULL 0
#define HEAP_SIZE 11300 //consommation : 11228
#define HEAP_SIZE2 4000


extern const unsigned char heap[HEAP_SIZE];
extern unsigned char* heap_ptr;
extern unsigned char heap2[HEAP_SIZE2];
extern unsigned char* heap_ptr2;

void my_malloc_init(void);
void *my_malloc(unsigned long len);
void my_free();
void *my_malloc2(unsigned long len);

#endif // MALLOC_H_INCLUDED


