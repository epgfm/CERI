# include <iostream>
using namespace std;

int main(int argc, char *argv[]) 
{ 
    int val = 7;
    cout << "val vaut: " << val << endl;
    {
        int val = 5;
        cout << "val vaut: "  << val << endl;    
    }
    cout << "val vaut: "  << val << endl;    
    return 0; 
}

