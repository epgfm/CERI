# include <iostream>
using namespace std;

int menu() { 
    int choix = 0; 
    while (choix < 1 || choix > 4) { 
        cout << "Menu :\n"; 
        cout << "1 : Poulet de dinde aux escargots\n"; 
        cout << "2 : Concombres sucres a la sauce de myrtilles\n"; 
        cout << "3 : Escalope de kangourou saignante \n"; 
        cout << "4 : La surprise du Chef\n"; 
        cout << "Votre choix ? "; 
        cin >> choix; 
    } 
    return choix; 
} 

int main(int argc, char *argv[]) { 
    switch (menu()) { 
        case 1: 
            cout << "Vous avez pris le poulet\n"; 
            break; 
        case 2: 
            cout << "Vous avez pris les concombres\n"; 
            break; 
        case 3: 
            cout << "Vous avez pris l'escalope\n"; 
            break; 
        case 4: 
            cout << "Vous avez pris la surprise du Chef !\n"; 
            break; 
    } 
    return 0; 
}
