#include <stdio.h>
#include <stdlib.h>

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
 * Sorts array with bubble sort in place.
 *
 * @param source The array we want to sort
 * @param length The length of the array
 */
void bubble_sort(char* source, int length)
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

int main(void)
{
    int length = 10;
    char arr[] = {1, 2, 3, 6, 7, 0, 9, 8, 5, 4};
    bubble_sort(arr, length);
    printarray(arr, length);
}
