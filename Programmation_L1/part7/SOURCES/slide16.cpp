# include <iostream>
# include <string>

using namespace std;

int main()
{
    char buffer[20];
    string str("Test string...");
    size_t length = str.copy(buffer, 6, 5);
    buffer[length] = '\0';
    cout << "buffer contains: " << buffer << '\n';
    return 0;
}
