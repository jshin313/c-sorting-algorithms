Description
===========

Just some sorting algos in C so I can practice implementing stuff.

Note: “Array”, “Buffer”, and “List” are used interchangeably since they’re sort of all the same things.

The table below is from [wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm).

Warning
=======

All of these implementations are probably not that efficient or the best. I might have even made some mistakes in the implementation. As stated above, these sorting algos are mainly for me to refer back to and practice my skillz.

Compilation
===========

``` console
$ make
$ ./testcases
```

Table
=====

|                |                              |                              |                              |                |            |            |                 |                                          |
|:--------------:|:----------------------------:|:----------------------------:|:----------------------------:|:--------------:|:----------:|:----------:|:---------------:|:----------------------------------------:|
|    **Name**    |           **Best**           |           **Worst**          |          **Average**         |   **Memory**   | **Stable** | **Method** |    **Notes**    |                 **Code**                 |
|   Bubble Sort  |           *O*(*n*)           |     *O*(*n*<sup>2</sup>)     |     *O*(*n*<sup>2</sup>)     |     *O*(1)     |     Yes    |  Swapping  | Small code size |    [bubblesort.c](algos/bubblesort.c)    |
| Selection Sort |     *O*(*n*<sup>2</sup>)     |     *O*(*n*<sup>2</sup>)     |     *O*(*n*<sup>2</sup>)     |     *O*(1)     |     No     |  Selection |                 | [selectionsort.c](algos/selectionsort.c) |
| Insertion Sort |           *O*(*n*)           |     *O*(*n*<sup>2</sup>)     |     *O*(*n*<sup>2</sup>)     |     *O*(1)     |     Yes    |  Insertion |                 | [insertionsort.c](algos/insertionsort.c) |
|   Merge Sort   | *O*(*n*log<sub>2</sub>(*n*)) | *O*(*n*log<sub>2</sub>(*n*)) | *O*(*n*log<sub>2</sub>(*n*)) |    *O*(*n*)    |     Yes    |   Merging  |                 |     [mergesort.c](algos/mergesort.c)     |
|  Counting Sort |        *O*(*n* + *k*)        |        *O*(*n* + *k*)        |        *O*(*n* + *k*)        | *O*(*n* + *k*) |     Yes    |            |  k is the range |  [countingsort.c](algos/countingsort.c)  |

Bubble Sort
===========

[bubblesort.c](algos/bubblesort.c) Keep comparing adjacent elements in the array and “bubble” up the largest element by swapping. There are n rounds and after k rounds, the kth largest element is in the right position.

    [3] [2] [4] [5] [1] Starting array
    [2] [3] [4] [5] [1] Swap 2 and 3
    [2] [3] [4] [1] [5] Swap 5 and 1
    [2] [3] [1] [4] [5] Swap 4 and 1
    [2] [1] [3] [4] [5] Swap 3 and 1
    [1] [2] [3] [4] [5] Swap 2 and 1

Selection Sort
==============

[selectionsort.c](algos/selectionsort.c) There are n rounds. During each round, find the smallest element and swap it with the element at the beginning. Repeat.

    [3] [2] [4] [5] [1] Starting array
    [1] [2] [4] [5] [3] Swap 3 and 1
    [1] [2] [4] [5] [3] 2 is already in place
    [1] [2] [3] [5] [4] Swap 4 and 3
    [1] [2] [3] [4] [5] Swap 4 and 5

Insertion Sort
==============

[insertionsort.c](algos/insertionsort.c) Have a “sorted” list and an “unsorted” list. At the beginning the sorted list is just the first element of the array and the unsorted part is the rest of the array. During each round, insert the first element of the unsorted list into the correct position at the sorted list. Inserting might involve shifting the unsorted part over to the right.

    [3] [2] [4] [5] [1] Starting array
    [2] [3] [4] [5] [1] Insert 2 before 3
    [2] [3] [4] [5] [1] Insert 4 after 3
    [2] [3] [4] [5] [1] Insert 5 after 4
    [1] [2] [3] [4] [5] Insert 1 before 2

Merge Sort
==========

Counting Sort
=============
