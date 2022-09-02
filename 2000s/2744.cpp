#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if('A' <= ch && ch <= 'Z')
        {
            ch += 32;
            cout << ch;
        }
        else
        {
            ch -= 32;
            cout << ch;
        }
    }
}