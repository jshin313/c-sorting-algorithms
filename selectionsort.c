#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Just prints out the contents of an array 
 *
 * @param arr The input array
 * @param length The length of the array
 */
void printarray(char *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * Swaps the elmeent at p1 with whatever's at p2
 *
 * @param p1 Pointer to first elem
 * @param p2 Pointer to second elem 
 */
void swap(char *p1, char *p2)
{
   int tmp = *p1; 
   *p1 = *p2;
   *p2 = tmp;
}

/**
 * Sorts array with selection sort in place. 
 *
 * @param source The source buffer
 * @param length The length of the buffer
 */
void selection_sort(char *source, int length)
{
    
    // Iterate over entire array
    // The i var keeps track of where the sorted/unsorted part of the array is
    // The length of the sorted part of the array is also the equal to the 
    // index of the beginning of the unsorted part of the array which is kept track by the i var
    for (int i = 0; i < length; i++)
    {
        // Keep track of the smallest element in the unsorted part of the array
        // First make "smallest" the first element of the unsorted region of the array
        char *smallest = &source[i];
        
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
        printf("Swapping %d with %d\n", source[i], *smallest);
    }
}

int main(void)
{
    int length = 10;
    char arr[] = {1, 2, 3, 6, 7, 0, 9, 8, 5, 4};
    selection_sort(arr, length);
    printarray(arr, length);
}
