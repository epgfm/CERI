# include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{ 
    int tableau[4] = {4, 3, 10, 1}, i; 
    for (i = 0 ; i < 4 ; i++)
        cout << '[' << tableau[i] << ']';
    cout << endl ;
    return 0; 
}

