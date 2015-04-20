# include <iostream>
# include <string>

using namespace std;

int main(void)
{
    string s1, s2, s3;
    cout << "Tapez une chaine : "; getline(cin, s1);
    cout << "Tapez une chaine : "; getline(cin, s2);
    s3 = s1 + s2;
    cout << "Voici la concatenation des 2 chaines : ";
    cout << s3 << endl;
    return 0;
}
