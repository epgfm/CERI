# include <iostream>
using namespace std;

void produit_somme(int x, int y , int & s, int & p); 

int main(int argc, char *argv[]) 
{ 
    int x, y, p, s;
    cout << "Entrez les deux valeurs : ";
    cin >> x >> y; 
    produit_somme(x, y, s, p);
    cout << "La somme est : " << s << endl;
    cout << "Le produit est : " << p << endl;
    return 0; 
} 

void produit_somme(int x, int y, int & s, int & p) 
{
    s = x + y;
    p = x * y;
}

