# include <iostream>
# include "tata.h"
# include "toto.h"

using namespace std;

int main(int argc, char ** argv)
{

    cout << endl << endl ;

    cout << "This program uses two \"modules\": toto and tata." << endl ;

    cout << "For each module, the function headers are in the .h files "
         << "and the function implementations are in the .cc files." << endl ;

    cout << "Here's a call to a function from module toto: "; sayToto();
    cout << "Here's a call to a function from module tata: "; sayTata();

    cout << "See the Makefile and the sources for details on "
         << "split compilation." << endl ;

    cout << endl << endl ;

    return 0;

}
