/** Just tests all the sorting algos **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#include <bubblesort.h>
#include <insertionsort.h>
#include <selectionsort.h>
#include <mergesort.h>
#include <countingsort.h>

/** Used by qsort **/
int compare(const void* a, const void* b) 
{
    if (*(int *)a > *(int *)b) return  1;
    if (*(int *)b < *(int *)a) return -1;
    return 0;
}

/**
 * Just prints out the contents of an array and some additional info
 *
 * @param arr The input array
 * @param length The length of the array
 * @return number of characters written
 */
int printarray(int* arr, int length)
{
    int totalwritten = 0;
    int charswritten;

    for (int i = 0; i < length; i++)
    {
        printf("%d %n", arr[i], &charswritten);
        totalwritten += charswritten;
    }
    return totalwritten;
}

int test_sort(char* name, void (*func)(int*, int))
{
    int charswritten;
    printf("****************************** %s Test **********************************%n\n", name, &charswritten);
    puts("");

    for (int i = 10, count = 1; i < 1000000; i *= 10, count++)
    {
        int length = i;
        
        int* test = malloc(sizeof(int) * length);
        
        // Make a copy of the array
        int* copy = malloc(sizeof(int) * length);    

        srand(time(NULL));

        for (int j = 0; j < length; j++)
        {
            int random = rand() % 10000;
            test[j] = random;
            copy[j] = random;
        }
        

        // Make the output somewhat nice
        printf("        Test Case #%02d: Length of Test Case: 10^%d ", count, count);
        
        clock_t begin = clock(); // Start timer
        
        // Call the sort function
        (*func)(test, length);

        clock_t end = clock();

        /* printf("    "); */
        /* printarray(test, length); */
        /* puts(""); */

        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("took %lfs      ", time_spent);

        qsort(copy, length, sizeof(*copy), compare);
        if (!memcmp(copy, test, length * sizeof(*copy))) {
            printf("Passed!\n");
        }
        else {
            printf("Failed!\n");
        }
        free(copy);
        free(test);
    }

    puts("");
    for (int i = 0; i < charswritten; i++)
        printf("*");

    puts("\n");

    return 1;
}


int main(void)
{
    test_sort("Counting Sort", &countingsort);
    test_sort("Merge Sort", &mergesort);
    test_sort("Insertion Sort", &insertionsort);
    test_sort("Selection Sort", &selectionsort);
    /* test_sort("Bubble Sort", &bubblesort); */

}
