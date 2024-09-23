#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    str = str.substr(0, 3);

    if(str == "555")
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}