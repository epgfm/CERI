# include <iostream>
# include <stdlib.h>
using namespace std;
main(int argc, char **argv)
{
    int i = 0;
    int som = 0;
    while (i < 10)
    {
        som = som + i;
        i++;
        cout << "La valeur de i : " << i << endl;
    }
    cout << "La valeur de i à la sortie : " << i << endl;
    cout << "la somme des dix premiers: " << som << endl;
    return 0;
}

