#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    if(str == "M")
    {
        cout << "MatKor";
    }
    else if(str == "W")
    {
        cout << "WiCys";
    }
    else if(str == "C")
    {
        cout << "CyKor";
    }
    else if(str == "A")
    {
        cout << "AlKor";
    }
    else if(str == "$")
    {
        cout << "$clear";
    }
}