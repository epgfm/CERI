# include <iostream>
using namespace std;

void decoupeMinutes(int* pointeurHeures, int* pointeurMinutes); 

int main(int argc, char *argv[]) 
{ 
    int heures = 0, minutes = 90; 
    // On envoie l'adresse de heures et minutes
    decoupeMinutes(&heures, &minutes);
    // Cette fois, les valeurs ont été modifiées ! 
    cout << heures << " heures et " <<  minutes << " minutes " << endl;
    return 0; 
} 

void decoupeMinutes(int* pointeurHeures, int* pointeurMinutes) 
{
    *pointeurHeures = *pointeurMinutes / 60; 
    *pointeurMinutes = *pointeurMinutes % 60; 
}

