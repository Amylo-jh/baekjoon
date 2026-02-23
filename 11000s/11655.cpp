#include <iostream>
#include <string>

using namespace std;

char rot13(int ch)
{
    if ('a' <= ch && ch <= 'z')
    {
        ch += 13;
        if ('z' < ch)
        {
            ch -= 26;
        }
    }
    if ('A' <= ch && ch <= 'Z')
    {
        ch += 13;
        if ('Z' < ch)
        {
            ch -= 26;
        }
    }
    return ch;
}

int main()
{
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        cout << rot13(int(str[i]));
    }
}