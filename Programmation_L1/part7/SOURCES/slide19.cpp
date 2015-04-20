# include <iostream>
# include <string>

using namespace std;

int main(void)
{
    string s1, s2;
    char c1 [] = "BONJOUR";
    const char * c2;

    s1 = c1;
    cout << s1 << endl;
    s2 = "AU REVOIR";
    c2 = s2.c_str();
    cout << c2 << endl;

    return 0;
}

