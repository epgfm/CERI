# include <iostream>
# include <cstdlib>
# include <time.h>

using namespace std;


/*
 * \brief   Implementation of MergeSort algorithm.
 * \param   array   The array to be sorted.
 * \param   first   The first indice of the range to be sorted.
 * \param   last    The last  indice of the range to be sorted.
 *
 * The merge routine has a few more steps than what the pseudo code 
 * showed, but it's implementation-specific and was to be expected.
 *
 */
void mergeSort(int * array, int first, int last) {
    // Base case: If the array has length 1 then it's sorted: return.
    if (last == first)
        return;

    // Standard case: Recursive calls to sort the left and right half.
    int middle = first + ((last - first) / 2);
    mergeSort(array, first,    middle);
    mergeSort(array, middle + 1, last);

    // Then merge step of the two sorted sub-arrays into a temporary one.
    int size = (last - first) + 1;
    int * temporary = new int[size];

    int i = first;
    int j = middle + 1; 
    int k;
    for (k = 0 ; k < size ; ++k) {
        if (i > middle)
            temporary[k] = array[j++];  // i part is done: copy j.
        else if (j > last)
            temporary[k] = array[i++];  // j part is done: copy i.
        else if (array[i] < array[j])
            temporary[k] = array[i++];
        else
            temporary[k] = array[j++];
    }

    // Done, copy the result back into the original array;
    for (k = 0 ; first <= last ; ++first, ++k)
        array[first] = temporary[k];

    // Release extra memory space.
    delete [] temporary;

}



int main(void)
{

    srand(time(NULL));

    int n;

    cout << "Input array size: " ; cin >> n ;

    int * array = new int[n];


    for (int i = n - 1 ; i >= 0 ; --i)
        array[i] = rand() % 101;

    for (int i = 0 ; i < n ; ++i)
        cout << "[" << array[i] << "]";
    cout << endl ;

    mergeSort(array, 0, n - 1);

    for (int i = 0 ; i < n ; ++i)
        cout << "[" << array[i] << "]";
    cout << endl ;

    delete [] array;

    return 0;

}

