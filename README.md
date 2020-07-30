Description
===========

Just some sorting algos implemented in C so I can practice implementing stuff. Also some notes about different sorting algos.

Note: “Array”, “Buffer”, and “List” are used interchangeably since they’re sort of all the same things.

As stated above, these sorting algos are mainly for me to refer back to and practice my skillz. If you see any mistakes (in the code or in my notes below, feel free to create an issue or something.

Compilation
===========

``` console
$ make
$ ./testcases
```

Table
=====

The table below is from [wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm).

|                |                              |                              |                              |                           |            |              |                 |                                          |
|:--------------:|:----------------------------:|:----------------------------:|:----------------------------:|:-------------------------:|:----------:|:------------:|:---------------:|:----------------------------------------:|
|    **Name**    |           **Best**           |           **Worst**          |          **Average**         |         **Memory**        | **Stable** |  **Method**  |    **Notes**    |                 **Code**                 |
|   Bubble Sort  |           *O*(*n*)           |     *O*(*n*<sup>2</sup>)     |     *O*(*n*<sup>2</sup>)     |           *O*(1)          |     Yes    |   Swapping   | Small code size |    [bubblesort.c](algos/bubblesort.c)    |
| Selection Sort |     *O*(*n*<sup>2</sup>)     |     *O*(*n*<sup>2</sup>)     |     *O*(*n*<sup>2</sup>)     |           *O*(1)          |     No     |   Selection  |                 | [selectionsort.c](algos/selectionsort.c) |
| Insertion Sort |           *O*(*n*)           |     *O*(*n*<sup>2</sup>)     |     *O*(*n*<sup>2</sup>)     |           *O*(1)          |     Yes    |   Insertion  |                 | [insertionsort.c](algos/insertionsort.c) |
|   Merge Sort   | *O*(*n*log<sub>2</sub>(*n*)) | *O*(*n*log<sub>2</sub>(*n*)) | *O*(*n*log<sub>2</sub>(*n*)) |          *O*(*n*)         |     Yes    |    Merging   |                 |     [mergesort.c](algos/mergesort.c)     |
|  Counting Sort |        *O*(*n* + *k*)        |        *O*(*n* + *k*)        |        *O*(*n* + *k*)        |       *O*(*n* + *k*)      |     Yes    |   Non-comp   |  k is the range |  [countingsort.c](algos/countingsort.c)  |
|   Quick Sort   | *O*(*n*log<sub>2</sub>(*n*)) | *O*(*n*log<sub>2</sub>(*n*)) |     *O*(*n*<sup>2</sup>)     | *O*(log<sub>2</sub>(*n*)) |     No     | Partitioning |                 |     [quicksort.c](algos/quicksort.c)     |

Bubble Sort
===========

[bubblesort.c](algos/bubblesort.c)

Keep comparing adjacent elements in the array and “bubble” up the largest element by swapping. There are n rounds and after k rounds, the kth largest element is in the right position.

    [3 2 4 5 1] Starting array
    [2 3 4 5 1] Swap 2 and 3
    [2 3 4 1 5] Swap 5 and 1
    [2 3 1 4 5] Swap 4 and 1
    [2 1 3 4 5] Swap 3 and 1
    [1 2 3 4 5] Swap 2 and 1

    Best Case: [1 2 3 4 5]
    Worst Case: [5 4 3 2 1]

Selection Sort
==============

[selectionsort.c](algos/selectionsort.c)

There are n rounds. During each round, find the smallest element and swap it with the element at the beginning. Repeat.

    [3] [2] [4] [5] [1] Starting array
    [1] [2] [4] [5] [3] Swap 3 and 1
    [1] [2] [4] [5] [3] 2 is already in place
    [1] [2] [3] [5] [4] Swap 4 and 3
    [1] [2] [3] [4] [5] Swap 4 and 5

    Best Case = Worst Case

Insertion Sort
==============

[insertionsort.c](algos/insertionsort.c)

Have a “sorted” list and an “unsorted” list. At the beginning the sorted list is just the first element of the array and the unsorted part is the rest of the array. During each round, insert the first element of the unsorted list into the correct position at the sorted list. Inserting might involve shifting the unsorted part over to the right.

    [3] [2 4 5 1] Starting array
    [2 3] [4 5 1] Insert 2 before 3
    [2 3 4] [5 1] Insert 4 after 3
    [2 3 4 5] [1] Insert 5 after 4
    [1 2 3 4 5] Insert 1 before 2

    Best Case: [1 2 3 4 5]
    Worst Case: [5 4 3 2 1]

Merge Sort
==========

[mergesort.c](algos/mergesort.c)

1.  Divide the array/subarray in half

2.  Recursively sort the two halves

3.  Merge the two halves together

The recursion takes *O*(*l**o**g*<sub>2</sub>(*n*)) sublevels and merging takes *O*(*n*) time.

    [3 2 4 5 1]         Starting array
    [3 2] [4 5 1]       Split the Array
    [3 2] [4] [5 1]     Split the Arrays
    [3] [2] [4] [5] [1] Split the Arrays. It took log(n) steps to reach the base case
    [2 3] [4] [1 5]     Merge Subarrays
    [2 3] [1 4 5]       Merge Subarrays
    [1 2 3 4 5]         Merge Subarrays

[Here](https://youtu.be/alJswNJ4P3U) for a more in-depth analysis on the runtime efficiency. [This](https://stackoverflow.com/q/24594112/9512643) talks about the worst case for merge sort.

Counting Sort
=============

[counting.c](algos/counting.c)

Create a “bookkeeping” array of length k, where k is the range of the dataset. Keep track of how many times each element appears with the bookkeeping array. Constructing the bookkeeping array takes *O*(*n*) time and making the sorted array takes *O*(*k*) time. Thus the total time is *O*(*n* + *k*).

    [3 2 4 5 1]         Starting array
    [1 1 1 1 1]         Bookkeeping array

Quick Sort (Not Implemented Yet)
==========

[quicksort.c](algos/quicksort.c)

**Using External Memory**

-   Choose a pivot (in this example, the first element).

-   All elements to the less than the pivot go to the “left” subarray and those greater go to the “right” subarray.

-   Choose a pivot for each subarray and repeat the above step

-   Once the base case is reached (subarray length of 1), just combine the subarrays.

**Using stack space (“In Place”)**

-   

<!-- -->

    [3 2 4 5 1]         Starting array

    Worst Case (If you make the first item the pivot): [1 2 3 4 5] 

Note: In the actual code, I use the “median-of-three” rule to choose the pivot (median of first, middle, and last elements).
