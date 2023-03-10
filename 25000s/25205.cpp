#include <iostream>
#include <string>

using namespace std;

int main()
{
    int length;
    string str;
    cin >> length >> str;

    switch (str[length-1])
    {
        case 'q':
        case 'w':
        case 'e':
        case 'r':
        case 't':
        case 'a':
        case 's':
        case 'd':
        case 'f':
        case 'g':
        case 'z':
        case 'x':
        case 'c':
        case 'v':
            cout << "1";
            break;
        default:
            cout << "0";
            break;
    }
    
}