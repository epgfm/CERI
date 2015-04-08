# include <iostream>
# include <geometry.h>

using namespace std;

int main(void)
{

    cout << endl << "[Library geometry test program]" << endl << endl ;

    cout << "Calling function display_circle() "
         << "from libgeometry, module circle." << endl ;
    display_circle();

    cout << endl << endl ;

    cout << "Calling function display_square() "
         << "from libgeometry, module square." << endl ;
    display_square();

    return 0;

}
