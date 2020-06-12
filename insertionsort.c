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
 * Inserts element at position in dest.
 *
 * @param dest The destination buffer
 * @param position The index to insert element
 * @param element The element to insert
 * @param length The length of the array
 */
void insert(char *dest, int position, char element, int length)
{
    // Shift everything to the right of the position we're inserting at by one
    // to make room for the insertion
    memcpy(dest + position + 1, dest + position, (length - 1) - position);

    // Insert at position
    dest[position] = element;
}

/**
 * Sorts array with insertion sort and places sorted array in dest.
 *
 * @param source The source buffer
 * @param dest The buffer were the sorted array is stored
 * @param length The length of the buffers (Note: Must be same length)
 */
void insertion_sort(char *source, char *dest, int length)
{
    // Make a sorted list of length 1
    dest[0] = source[0];
    int sorted_length = 1;

    // Iterate over unsorted list
    for (int i = 1; i < length; i++)
    {
        // Iterate over sorted list
        for (int j = 0; j < sorted_length + 1; j++)
        {
            // Insert element if the element we're comparing is less than the corresponding element in the dest buf, 
            // or if we're at the end of the sorted list 
            if (source[i] < dest[j] || j == sorted_length)
            {
                printf("Inserting %d at index %d\n", source[i], j);
                insert(dest, j, source[i], length);
                sorted_length++;
                break;
            }
        } 
    }
}

int main(void)
{
    int length = 10;
    char arr[] = {1, 2, 3, 6, 7, 0, 9, 8, 5, 4};
    char *newarr = (char *)malloc(length * sizeof(char));
    insertion_sort(arr, newarr, length);
    printarray(newarr, length);
}
