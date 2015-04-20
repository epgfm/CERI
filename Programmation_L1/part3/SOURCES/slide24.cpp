# include <iostream> 

using namespace std;
/* Je mets le prototype en haut. Comme c'est un tout petit programme je ne
   le mets pas dans un .h, mais en temps normal (dans un vrai programme)
   j'aurais placé le prototype dans un fichier .h bien entendu ;o) */ 

void decoupeMinutes(int heures, int minutes);

int main(int argc, char *argv[]) 
{ 
    int heures = 0, minutes = 90; 

    decoupeMinutes(heures, minutes); 
    cout << heures << "  heures et " << minutes << " minutes " << endl; 
    return 0; 
} 

void decoupeMinutes(int heures, int minutes) 
{ 
    heures = minutes / 60; // 90 / 60 = 1 
    minutes = minutes % 60; // 90 % 60 = 30
}

