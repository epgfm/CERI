#include <iostream>
#include <math.h> 

using namespace std;

float racine_carre(float nombre) 
{ 
    return sqrt(nombre); 
} 

int main(int argc, char *argv[]) 
{ 
    float nombreEntre = 0, nombre_RC = 0;     
    cout << "Entrez un nombre positif... ";
    cin >> nombreEntre; 
    if (nombre_RC >= 0.0)    
    {
        nombre_RC = racine_carre(nombreEntre);
        cout << "La racine carre de ce nombre est " << nombre_RC << endl;     
    }
    else
    {
        cout << "Le nombre doit etre positif\n";
    }
    return 0; 
} 
