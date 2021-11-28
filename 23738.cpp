//https://www.acmicpc.net/contest/problem/725/1

#include <iostream>

using namespace std;

int main()
{
    char word[101] = {0};
    cin >> word;

    for (int i = 0; word[i] != 0; i++)
    {
        switch (word[i])
        {
        case 'B':
            cout << "v";
            break;
        case 'E':
            cout << "ye";
            break;
        case 'H':
            cout << "n";
            break;
        case 'P':
            cout << "r";
            break;
        case 'C':
            cout << "s";
            break;
        case 'Y':
            cout << "u";
            break;
        case 'X':
            cout << "h";
            break;
        default:
            cout << char(word[i]+32);
            break;
        }
    }
}