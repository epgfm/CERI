# include <iostream>

using namespace std;

// Prototype de la fonction d'affichage 
void affiche(int *, int); 

int main(int argc, char *argv[]) 
{ 
    int T[4] = {10, 15, 3};     
    // On affiche le contenu du tableau 
    affiche(T, 4); 
    return 0; 
} 

void affiche(int *t, int taille) 
{ 
    int i; 
    for (i = 0 ; i < taille ; i++) 
    { 
        cout << t[i] << endl; 
    } 
}
