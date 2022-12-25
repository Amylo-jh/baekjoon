#include <iostream>
#include <string>

using namespace std;

int main()
{
    while(!cin.eof())
    {
        string str;
        getline(cin, str);
        cout << str << "\n";
    }
}