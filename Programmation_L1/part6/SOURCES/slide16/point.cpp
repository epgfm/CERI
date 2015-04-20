# include "point.h"

using namespace std;

Point::Point(double abs, double ord) {
    x = abs;
    y = ord;
}

void Point::deplacer(double  dx, double dy) {
    x += dx ;
    y += dy;
}

void Point::afficher() {
    cout << '(' << x << ", " << y << ')' << endl;
}

