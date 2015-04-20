# include <iostream>
# include <sstream>
# include <string> 

using namespace std;

int main(void)
{
    string s;
    cout << "Tapez une chaine : "; getline(cin, s);
    istringstream istr(s);
    int i;
    if (istr >> i)
        cout << "VOUS AVEZ TAPE L'ENTIER " << i << endl;
    else
        cout << "VALEUR INCORRECTE" << endl;
    return 0;
}


