#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    while(cin.eof() == false)
    {
        cout << str << "\n";
        getline(cin, str);
    }
}