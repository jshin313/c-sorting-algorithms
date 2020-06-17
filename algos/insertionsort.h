/** 
 * Inserts element at position in dest.
 *
 * @param dest The destination buffer
 * @param position The index to insert element
 * @param element The element to insert
 * @param length The length of the array
 */
void insert(int*dest, int position, int element, int length);

/**
 * Sorts array with insertion sort and places sorted array in dest.
 *
 * @param source The source buffer
 * @param dest The buffer were the sorted array is stored
 * @param length The length of the buffers (Note: Must be same length)
 */
void insertionsort(int* source, int length);
