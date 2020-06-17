#include <stdlib.h>
#include <stdio.h>

#include "bubblesort.h"
#include "swap.h"

/**
 * Sorts array with bubble sort in place.
 *
 * @param source The array we want to sort
 * @param length The length of the array
 */
void bubblesort(int* source, int length)
{
    // Iterate over the array 
    // The i var keeps track of the unsorted region of the array
    for (int i = length - 1; i > 0; i--)
    {
        // Iterate over the unsorted region of the array
        for(int j = 0; j < i; j++)
        {
            // If adjacent elements in the unsorted region are out of place, swap them
            if (source[j] > source[j + 1])
            {
                swap(&source[j], &source[j+1]);
            }
        }
    }
}

