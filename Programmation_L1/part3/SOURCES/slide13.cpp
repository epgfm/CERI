#include <iostream> 

using namespace std;

// La ligne suivante est le prototype de la fonction aireRectangle : 
double aireRectangle(double largeur, double hauteur); 
int main(int argc, char *argv[]) 
{ 
    cout << "Rectangle de largeur 5 et hauteur 10. Aire "
         << aireRectangle(5, 10) << endl ; 
    cout << "Rectangle de largeur 2.5 et hauteur 3.5. Aire "
         << aireRectangle(2.5, 3.5) << endl ; 
    cout << "Rectangle de largeur 4.2 et hauteur 9.7. Aire "
         << aireRectangle(4.2, 9.7) << endl ; 
    return 0; 
} 

/* Notre fonction aireRectangle peut maintenant être mise n'importe
   où dans le code source : */ 

double aireRectangle(double largeur, double hauteur) 
{ 
    return largeur * hauteur;
}

