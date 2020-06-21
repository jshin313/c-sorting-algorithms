#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "swap.h"

/** 
 * Inserts element at position in dest.
 *
 * @param dest The destination buffer
 * @param position The index to insert element
 * @param element The element to insert
 * @param length The length of the array
 */
void insert(int* dest, int position, int element, int length)
{
    // Shift sorted list that is to the right of the element we're inserting to the right by one
    // to make room for the insertion
    memcpy(dest + position + 1, dest + position, length * sizeof(int));
    //printf("Size: %d\n", size);

    // Insert at position
    dest[position] = element;
}

/**
 * Sorts array with insertion sort 
 *
 * @param source The source buffer
 * @param length The length of the buffers (Note: Must be same length)
 */
void insertionsort(int* source, int length)
{
    // Make a sorted list of length 1
    int sorted_length = 1;

    // Iterate over unsorted list
    for (int i = 1; i < length; i++)
    {
        // Iterate over sorted list
        for (int j = 0; j < sorted_length + 1; j++)
        {
            // Insert element if the element we're comparing is less than 
            // the corresponding element in the dest buf, or if we're at 
            // the end of the sorted list 
            if (source[i] < source[j] || j == sorted_length) {
#ifdef DEBUG
                printf("Inserting %d at index %d\n", source[i], j);
#endif

                insert(source, j, source[i], sorted_length - j);
                sorted_length++;
                break;
            }
        } 
    }
}

