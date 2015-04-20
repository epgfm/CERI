# include <iostream>
using namespace std;

typedef struct Point{
    int x;
    int y;
} POINT;   

void saisir_Point(POINT p) {
    cout << "Entrez x du point : ";
    cin >> p.x;
    cout << "Entrez y du point: ";
    cin >> p.y; 
}

void affiche_Point(POINT p) {
    cout << "(" << p.x << ", " << p.y << ")"
         << endl;
}

int main(int argc, char **argv)
{
       POINT a;
   a.x = 0;
   a.y = 0;
   cout << "Avant saisie : ";
   affiche_Point(a);
   saisir_Point(a);
   cout << "Après saisie : ";
   affiche_Point(a);
   return 0;
}


