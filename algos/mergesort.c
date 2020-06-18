#include "mergesort.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Assumes p1 and p2 are really just pointers to the original arr[]
// Also assumes that p1 and p2 are right next to each other and contiguous
// p1 should be the "left" subarray and p2 the "right" subarray
void merge(int* p1, int* p2, int len1, int len2)
{
    
#ifdef DEBUG
    printf("Merging: ");
    printarray(p1, len1);
    printf("and ");
    printarray(p2, len2);
    puts("");
#endif

    // Copy p1 and p2 into tmp1 and tmp2, respectively
    // since we're going to overwrite them
    int tmp1[len1], tmp2[len2];
    memcpy(tmp1, p1, sizeof(*p1) * len1);
    memcpy(tmp2, p2, sizeof(*p2) * len2);
    

    int i = 0, j = 0, k = 0;
    
    while (i < len1 && j < len2)
    {
        if (tmp1[i] <= tmp2[j])
        {
            p1[k] = tmp1[i];
            i++;
        }
        else
        {
            p1[k] = tmp2[j];
            j++;
        }
        k++;
    }
    
    // We'll finish going through either tmp1 or tmp2
    // so just append the rest of the data we didn't copy over
    if (i < len1)
    {
        memcpy(p1 + k, tmp1 + i, (len1 - i) * sizeof(*p1));
    }
    else if (j < len2)
    {
        memcpy(p1 + k, tmp2 + j, (len2 - j) * sizeof(*p1));
    }


}

void mergesort(int* src, int length)
{
    if (length == 1)
    {
        return;
    }
    
    int half = (length)/2;
    mergesort(src, half);
    mergesort(src + half, length - half);

    merge(src, src + half, half, length - half);

    return;
}
