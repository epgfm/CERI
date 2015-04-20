# ifndef _POINT_H_
# define _POINT_H_

# include <iostream>

class Point {

    private :

        double x;
        double y;

    public :

        Point(double , double);
        void deplacer(double, double);
        void afficher();

};

# endif // _POINT_H_

