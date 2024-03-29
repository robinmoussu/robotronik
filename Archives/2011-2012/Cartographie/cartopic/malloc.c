#include "malloc.h"

void my_malloc_init(void)
{
    heap_ptr = heap;
    heap_ptr2 = heap2;
}

void *my_malloc(unsigned long len)
{
    unsigned char *p = heap_ptr;
    heap_ptr += len;
    if (heap_ptr >= heap + HEAP_SIZE)
    {
        LATBbits.LATB12 = 1;//debug LED
        return NULL;
    }
    else
        return p;
}


void my_free(void* p)
{
    // do nothing for heap
    heap_ptr2 = heap2; // heap2 est remis � zero
}

void *my_malloc2(unsigned long len)
{
    unsigned char *p2 = heap_ptr2;
    heap_ptr2 += len;
    if (heap_ptr2 >= heap2 + HEAP_SIZE2)
    {
        LATBbits.LATB12 = 1;//Debug LED
        return NULL;
    }
    else
        return p2;
}

