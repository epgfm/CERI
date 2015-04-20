# include <iostream>
# include <string>

using namespace std;

int main(void)
{
    string s = "BONJOUR";
    int i, taille = s.size();
    cout << "La chaine comporte " << taille << " caractères." << endl;

    for (i = 0 ; i < taille ; i++)
        cout << "caractère " << i << " = " << s.at(i) << endl;

    return 0;
}
