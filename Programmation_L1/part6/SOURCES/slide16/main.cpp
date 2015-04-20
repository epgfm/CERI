# include "point.h"

int main(int argc, char ** argv)
{
    Point a(5.0, 7.1);
    a.afficher();
    a.deplacer(-1.0, 8.3);
    a.afficher();
    return 0;
}

