# include <iostream>
using namespace std;

void triplePointeur(int *); 

int main(int argc, char *argv[]) 
{ 
    int n = 5; 
    triplePointeur(&n); // On envoie l'adresse de nombre à la fonction 

    // On affiche la variable nombre. La fonction a directement modifié la 
    // valeur de la variable car elle connaissait son adresse 
    cout << n << endl; 
    return 0; 
} 

void triplePointeur(int *pn) 
{ 
    *pn = 3 * (*pn); // On multiplie par 3 la valeur de la variable nombre 
}

