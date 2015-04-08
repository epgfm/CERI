# include <iostream>
# include <fstream>

using namespace std;

void swap(int & a, int & b) {
    int temporary = a;
    a = b;
    b = temporary;
}



/**
 * \brief Choose pivot subfunction. 
 *
 * Choose amongst the elements of the currently considered array which
 * element we'll use as a pivot. This is the "Median of three" Selection
 * method.
 *
 */
int choosePivot(int * array, int first, int last) {
    int l = first;
    int r = last;
    int m = first + ((last - first) / 2);

    if ((array[l] <= array[m] && array[m] <= array[r]) || 
        (array[r] <= array[m] && array[m] <= array[l]))
        // m is the median.
        return m;
    if ((array[m] <= array[l] && array[l] <= array[r]) || 
        (array[r] <= array[l] && array[l] <= array[m]))
        // l is the median.
        return l;
    if ((array[l] <= array[r] && array[r] <= array[m]) || 
        (array[m] <= array[r] && array[r] <= array[l]))
        // r is the median.
        return r;

}



/**
 * \brief Partition subroutine.
 *
 * Reorganize the array in a partion around the chosen pivot.
 * This procedure runs in linear time and when it completes the array looks
 * like that: [ Elements < pivot ][pivot][ Elements > Pivot]
 *
 */
void partition(int * array, int & pivot, int first, int last) {
    // Swap pivot with first element.
    swap(array[pivot], array[first]);
    pivot = array[first];
    int i = first + 1, j = first + 1;
    while (j <= last) {
        if (array[j] < pivot) {
            swap(array[j], array[i]);
            ++i;
        }
        ++j;
    }
    swap(array[first], array[i - 1]);
    pivot = i - 1;
}



/**
 * \brief QuickSort algorithm
 *
 * Divide and conquer algorithm that sorts the given array in-place with very
 * few overhead.
 *
 */
void QuickSort(int * array, int first, int last) {

    if (first >= last)
        return;

    int pivot = choosePivot(array, first, last);

    partition(array, pivot, first, last);    

    QuickSort(array,     first, pivot - 1);
    QuickSort(array, pivot + 1,      last);

}




/** 
 * \brief Test program 
 * 
 * Test the QuickSort algorithm on an array given as a text file.
 * 
 */
int main(void)
{

    int * array = new int[10001];

    fstream f;

    f.open("TestFile.txt", ios::in);

    int i = 0;

    while (f)
        f >> array[i++];

    f.close();

    int size = i - 1;

    for (i = 0 ; i < size ; ++i)
        cout << "[" << array[i] << "]";
    cout << endl ;


    QuickSort(array, 0, size - 1);

    for (i = 0 ; i < size ; ++i)
        cout << "[" << array[i] << "]";
    cout << endl ;

    return 0;

}
