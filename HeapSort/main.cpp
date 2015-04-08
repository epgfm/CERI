# include <iostream>
# include <Heap.h>
# include <time.h>
# include <stdlib.h>

using namespace std;

int main(int argc, char ** argv) {

    cout << "Greetings, Overlord!" << endl ;

    int n;
    cout << "Input length of the array to sort : "; cin >> n;
    int * T = new int[n];

    srand(time(NULL));
    for (int i = 0 ; i < n ; ++i)
        T[i] = rand() % 100;

    Heap::sort(n, T);

    for (int i = 0 ; i < n ; ++i)
        cout << "[" << T[i] << "]"; 
    cout << endl;

    return 0;

}    
