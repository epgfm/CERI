# include <iostream>
using namespace std;

int incremente(); 

int main(int argc, char *argv[]) 
{ 
    cout << incremente() << endl; 
    cout << incremente() << endl; 
    cout << incremente() << endl; 
    cout << incremente() << endl; 
    return 0; 
}
 
int incremente() 
{ 
    static int nombre = 0; 
    nombre++; 
    return nombre; 
}

