# include <iostream>

using namespace std;


//---------------------- This would be in the .h file. ----------------------//

class Comptable {

    private :

        static int compteur;

    public :

        Comptable();
       ~Comptable();

};



//--------------------- This would be in the .cpp file ----------------------//

int Comptable::compteur = 0;

Comptable::Comptable() {
    compteur++;
    cout << " ++ il y a " << compteur
         << " objets." << endl;
}


Comptable::~Comptable() {
    compteur--;
    cout << " -- il y a " << compteur
         << " objets." << endl;
}

void fonction()
{
    Comptable u, v;
}



//-------------------- This would be the main.cpp file. ---------------------//

int main(int argc, char ** argv)
{
    Comptable a;
    fonction();
    Comptable b;
    return 0;
}

