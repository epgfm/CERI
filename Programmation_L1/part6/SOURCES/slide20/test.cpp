# include "test.h"

using namespace std;

Test::Test(int n)
{
    num = n;
    cout << " ++ appel du constructeur --> num = "
         << num << endl;
}

Test::~Test()
{
    cout << " -- appel du destructeur --> num = "
         << num << endl ;
}

