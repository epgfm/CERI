# include <iostream> 
# include <stdlib.h> 
using namespace std;
int main(int argc, char *argv[]) 
{ 
    int age;
    cout << "Quel est votre age ? " ;
    cin >> age;

    if (age >= 18) {
        cout << "Vous etes majeur !\n";
    }
    else if (age > 11) {
        cout << "Vous etes ado !\n";
    }
    else {
        cout << "Tu es un enfant !\n";
    }

    return 0; 
}
