# include <iostream>
# include <stdlib.h>
using namespace std;

int resultat = 0; // Déclaration de variable globale 

void triple(int nombre); // Prototype de fonction
 
int main(int argc, char *argv[]) 
{ 
    triple(15);  /* On appelle la fonction triple, qui modifie
                    la variable globale resultat  */
    // On a accès à resultat 
    cout << "Le triple de 15 est: " << resultat << endl; 
    return 0; 
}
 
void triple(int nombre) 
{ 
    resultat = 3 * nombre; 
}

