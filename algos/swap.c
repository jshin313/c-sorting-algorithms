#include "swap.h"

/**
 * Swaps the elmeent at p1 with whatever's at p2
 *
 * @param p1 Pointer to first elem
 * @param p2 Pointer to second elem 
 */
void swap(int* p1, int* p2)
{
   int tmp = *p1; 
   *p1 = *p2;
   *p2 = tmp;
}
