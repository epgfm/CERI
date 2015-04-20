# include <iostream> 
# include <stdlib.h>
using namespace std;
int main(int argc, char *argv[]) 
{ 
    int choixMenu; 
    cout << "=== Menu ===\n\n"; 
    cout << "1. Royal Cheese\n"; 
    cout << "2. Mc Deluxe\n"; 
    cout << "3. Mc Bacon\n"; 
    cout << "4. Big Mac\n";
    cout << "\nVotre choix ? "; 
    cin >> choixMenu; 
    switch (choixMenu) 
    { 
        case 1 : 
            cout << "Vous avez choisi le Royal Cheese. ! " << endl;
            break; 
        case 2 : 
            cout << "Vous avez choisi le Mc Deluxe !" << endl;     
            break; 
        case 3 : 
            cout << "Vous avez choisi le Mc Bacon !" << endl; 
            break; 
        case 4 : 
            cout << "Vous avez choisi le Big Mac !" << endl; 
            break; 
        default : 
            cout << "Vous n'avez pas rentre un nombre correct ! " << endl; 
            break; 
    } 
    return 0;
}
