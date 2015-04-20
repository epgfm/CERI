# include <iostream> 

using namespace std;

int triple(int nombre) 
{ 
    return 3 * nombre; 
} 

int main(int argc, char *argv[]) 
{ 
    int nombreEntre = 0, nombreTriple = 0;     
    cout << "Entrez un nombre... ";
    cin >> nombreEntre; 
    nombreTriple = triple(nombreEntre); 
    cout << "Le triple de ce nombre est " << nombreTriple << endl;
    return 0; 
}
