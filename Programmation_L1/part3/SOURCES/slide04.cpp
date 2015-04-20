# include <iostream> 
# include <stdlib.h> 
# include <time.h> 

using namespace std;

int main (int argc, char** argv) 
{ 
    int nombreMystere = 0, nombreEntre = 0; 
    const int MAX = 100, MIN = 1;
    // Génération du nombre aléatoire
    srand(time(NULL));
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN; 
    
    // La boucle du programme. Elle se répète tant que l'utilisateur n'a
    // pas trouvé le nombre mystère
    do { 
        // On demande le nombre 
        cout << "Quel est le nombre ? "; 
        cin >> nombreEntre; 
        
        // On compare le nombre entré avec le nombre mystère 
        if (nombreMystere > nombreEntre) 
            cout << "C'est plus !\n\n"; 
        else if (nombreMystere < nombreEntre) 
            cout << "C'est moins !\n\n"; 
        else cout << "Bravo, vous avez trouvé le nombre !\n\n"; 

    } while (nombreEntre != nombreMystere); 
}

