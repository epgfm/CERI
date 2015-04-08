# include <Heap.h>

using namespace std;

/**
 * Constructor: the parameter is the capacity for the internal array.
 *
 */
Heap::Heap(int maxSize) {
    last = 0;
    max = maxSize;
    T = new int[max];
} 


/**
 * Swap the values of two cells of the array.
 * Cells have the indices a and b.
 *
 */
void Heap::swap(int a, int b) {
    int temp = T[a];
    T[a] = T[b];
    T[b] = temp;
}




/**
 * Return true if the Heap is empty.
 *
 */
bool Heap::isEmpty() { return last == 0; }



/**
 * Get the indice of the last element in the Heap.
 *
 */
int Heap::getLast() { return last; }



/**
 * Reset the Heap by 'forgetting' previously inserted elements.
 *
 */
void Heap::clear() { last = 0; }



/**
 * Display the internal array to standard output.
 *
 */
void Heap::disp() {
    for (int i = 0 ; i < last ; i++)
        cout << "[" << T[i] << "]";
    cout << endl;
}



/**
 * Check if the internal array is in a coherent Min-Heap status.
 *
 */
bool Heap::isHeap() {
    for (int i = 1 ; i < last ; i++)
        if (T[i] < T[(i - 1) / 2]) // Child bigger than parent: not a Min-Heap.
            return false;
    return true;
}



/**
 * Given an indice i, check if the corresponding cell has a child cell.
 *
 */
bool Heap::hasChild(int i) {
    return (2 * i + 1) < last;
}



/**
 * Given an indice i, return the indice of child cell of minimal value in  
 * the heap.
 * If it doesn't exists: return 0 (only the root cell can't be a child)
 *
 */
int Heap::getMinChild(int i) { 
    if (!hasChild(i))
        return 0;

    if (2 * i  + 2 >= last)  // If there is no second child,
        return 2 * i + 1; // return the index of the first child.

    if (T[2 * i + 1] < T[2 * i + 2])
        return 2 * i + 1;

    return 2 * i + 2;
}



/**
 * Add a value onto the Heap then restore Min-Heap status.
 *
 */
void Heap::add(int v) {
    T[last] = v;
    int i = last;
    while (T[i] < T[(i-1) / 2]) {
        swap(i, (i-1) / 2);
        i = (i-1) / 2;
    }
    last++;
}



/**
 * Pop the min value from the top of the tree (the root), restore Min-Heap
 * status and then return that value.
 *
 */
int Heap::popTop() {
    int min = T[0];
    last -= 1;
    T[0] = T[last]; // Switch last value to the root.
    int i = 0;
    int minChild;
    while (hasChild(i)) {
        minChild = getMinChild(i);
        if (T[i] > T[minChild]) {
            swap(i, minChild); 
            i = minChild;
        }
        else
            break;
    }
    return min;
}



/**
 * Sort the array using the HeapSort algorithm. O( nlog(n) )
 * This is so cool: exactly like insertion sort except the findMin subroutine
 * is replaced by popTop() which is O(1)! The add phase takes up log(n) and
 * there is n calls to popTop().
 *
 * Precondition: the array to sort can be fitted into the internal array.
 * (so arrayLength <= max) 
 */
void Heap::sort(int arrayLength, int * array) {
    Heap h(arrayLength);
    for (int i = 0 ; i < arrayLength ; i++)
        h.add(array[i]);
    while (not h.isEmpty()) 
        array[arrayLength - h.getLast()] = h.popTop();
}



/**
 * Destructor: releases allocated memory space.
 *
 */
Heap::~Heap() { delete [] T; }

