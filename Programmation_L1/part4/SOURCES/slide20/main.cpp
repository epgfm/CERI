# include <iostream>
# include "chaine.h"

using namespace std;

int main()
{
    const int N = 40;
    char ch1[N] = {'b', 'o', 'n', 'j', 'o', 'u', 'r', '\0'};
    char ch2[N] = "jour";

    if (contient(ch1, ch2))
        cout << ch1 << " contient " << ch2 << endl;
    else
        cout << ch1 << " ne contient pas " << ch2 << endl;

    return 0;
}
