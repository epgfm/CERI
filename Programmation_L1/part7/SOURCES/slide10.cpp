# include <iostream>
# include <string>

using namespace std;

int main()
{
  string str("Test string");

  for (int i = 0 ; i < str.length() ; ++i)
    cout << str[i];

  return 0;
}
