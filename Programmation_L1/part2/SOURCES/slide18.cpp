# include <iostream>
# include <stdlib.h>

int main(int argc, char *argv[]) 
{ 
    int age = 0; // On initialise la variable à 0 
    std::cout << "Quel age avez-vous ? "; 
    std::cin >> age; // On demande d'entrer l'age 
    std::cout << "Ah ! Vous avez donc " << age << "  ans ! \n\n"; 
    return 0; 
}
