#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    if(str[0] == 'E')
    {
        cout << "I";
    }
    else
    {
        cout << "E";
    }
    if(str[1] == 'S')
    {
        cout << "N";
    }
    else
    {
        cout << "S";
    }
    if(str[2] == 'T')
    {
        cout << "F";
    }
    else
    {
        cout << "T";
    }
    if(str[3] == 'J')
    {
        cout << "P";
    }
    else
    {
        cout << "J";
    }
}