#include <string.h>
#include <stdlib.h>
#include "countingsort.h"

int find_max(int* source, int length)
{
    int max = 0;
    for (int i = 0; i < length; i++)
    {
        if (source[i] > max)
            max = source[i];
    }
    return max;
}

int find_min(int* source, int length)
{
    int min = 0;
    for (int i = 0; i < length; i++)
    {
        if (source[i] < min)
            min = source[i];
    }
    return min;
}

void countingsort(int* source, int length)
{
    int max = find_max(source, length);
    int min = find_min(source, length);

    // Add 1 for zero
    int book_size = max - min + 1;
    int* bookkeeper = malloc(book_size * sizeof(int));
    memset(bookkeeper, 0, sizeof(*bookkeeper) * book_size);

    for (int i = 0; i < length; i++)
    {
#ifdef DEBUG
        printf("source[i]: %d ", source[i]);
#endif
        bookkeeper[source[i] - min]++;
    }


#ifdef DEBUG
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    printarray(bookkeeper, book_size);
    puts("");
#endif
 
    // Iterate over orignial source arrat
    for (int i = 0; i < length; i++)
    {
        // Iterate over the bookkeeper array
        for (int j = 0; j < book_size; j++)
        {
            // Fill source array
            for (; bookkeeper[j] > 0; bookkeeper[j]--)
            {
                source[i] = j + min;
                i++;
            }
        }
    }
    free(bookkeeper);
}
