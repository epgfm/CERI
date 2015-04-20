# include <iostream>

using namespace std;

typedef struct Point {
    double x;
    double y;
} POINT;

void affiche_point(POINT p) {
    cout << "Le point est : (" << p.x << ", " << p.y << ')' << endl;
}

int main(int argc, char *argv[]) 
{ 
    POINT a; 
    a.x = 10; 
    a.y = 20; 
    
    affiche_point(a);
    return 0; 
}
