# include <iostream>
# include <string>

int main()
{
  std::string str1, str2, str3;
  str1 = "Test string: ";   // c-string
  str2 = 'x';               // Single character
  str3 = str1 + str2;       // String

  std::cout << str3  << '\n';
  return 0;
}
