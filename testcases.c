#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <bubblesort.h>
#include <insertionsort.h>
#include <selectionsort.h>

/**
 * Just prints out the contents of an array and some additional info
 *
 * @param arr The input array
 * @param length The length of the array
 */
void printarray(int* arr, int length, int padding)
{
    printf("*");
    int totalwritten = 2;
    int charswritten;

    for (int i = 0; i < padding/2 - length; i++)
        printf(" ");

    totalwritten += padding/2 - length;

    for (int i = 0; i < length; i++)
    {
        charswritten = 0;
        printf("%d %n", arr[i], &charswritten);
        totalwritten += charswritten;
    }

    for (int i = 0; i < padding - totalwritten; i++)
        printf(" ");

    puts("*");
}

int compare(int* a, int* b) 
{
    if (*a > *b) return  1;
    if (*b < *a) return -1;
    return 0;
}

int test_inplace_sort(char* name, void (*func)(int*, int), int *tests[], int testnum)
{
    int charswritten;
    printf("*************************** %s Test ***********************%n\n", name, &charswritten);

    for (int i = 0; i < testnum; i++)
    {
        int length = sizeof(tests[i]);
        (*func)(tests[i], length);

        printarray(tests[i], length, charswritten);
        
        //qsort(arr, sizeof(arr)/sizeof(*arr), sizeof(*arr), comp);
            
    }
    for (int i = 0; i < charswritten; i++)
        printf("*");

    puts("\n");

    return 1;
}

int main(void)
{
    // Tests based off on the test at this link: https://reprog.wordpress.com/2010/05/20/what-does-it-take-to-test-a-sorting-routine/

    int arr1[] = { 0 };
    int arr2[] = { 0, 0 };
    int arr3[] = { 0, 0, 0 };
    int arr4[] = { 0, 1 };
    int arr5[] = { 1, 0 };
    int arr6[] = { 0, 1, 2 };
    int arr7[] = { 0, 2, 1 };
    int arr8[] = { 1, 0, 2 };
    int arr9[] = { 1, 2, 0 };
    int arr10[] = { 2, 0, 1 };
    int arr11[] = { 2, 1, 0 };
    int arr12[] = { 0, 1, 1 };
    int arr13[] = { 1, 0, 1 };
    int arr14[] = { 1, 1, 0 };
    int arr15[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int arr16[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int arr17[] = { 42, 9, 17, 54, 602, -3, 54, 999, -11 };
    int arr18[] = { -11, -3, 9, 17, 42, 54, 54, 602, 999 };
    int arr19[] = { 42, 9, 17, 54, 602, INT_MAX, 54, 999, -11 };
    int arr20[] = { -11, -3, 9, 17, 42, INT_MIN, 54, 602, 999 };

    int *tests[] = {arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr10, arr11, arr12, arr13, arr14, arr15, arr16, arr17, arr18, arr19, arr20};
    int testnum = 20;

    test_inplace_sort("Bubble Sort", &bubblesort, tests, testnum); 
    test_inplace_sort("Insertion Sort", &insertionsort, tests, testnum);
    test_inplace_sort("Selection Sort", &selectionsort, tests, testnum);
}
