#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "selectionsort.h"
#include "swap.h"
/**
 * Sorts array with selection sort in place. 
 *
 * @param source The source buffer
 * @param length The length of the buffer
 */
void selectionsort(int* source, int length)
{
    
    // Iterate over entire array
    // The i var keeps track of where the sorted/unsorted part of the array is
    // The length of the sorted part of the array is also the equal to the 
    // index of the beginning of the unsorted part of the array which is kept track by the i var
    for (int i = 0; i < length; i++)
    {
        // Keep track of the smallest element in the unsorted part of the array
        // First make "smallest" the first element of the unsorted region of the array
        int* smallest = &source[i];
        
        // Iterate over unsorted part of the array and find the smallest elment in the unsorted part
        for (int j = i + 1; j < length; j++)
        {
            if (source[j] < *smallest)
            {
                smallest = &source[j];
            }
        }

        // Swap the current smallest element with the whatever's at the beginning of the unsorted part of the array
        swap(&source[i], smallest);

#ifdef DEBUG
        printf("Swapping %d with %d\n", source[i], *smallest);
#endif

    }
}
