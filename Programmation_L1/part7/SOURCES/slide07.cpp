# include <iostream>
# include <string>

using namespace std;

int main()
{
    string str("Test string");

    for (string::iterator it = str.begin() ; it != str.end() ; it++)
        cout << *it;

    cout << '\n';
    return 0;
}
