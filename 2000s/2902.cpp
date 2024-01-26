#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        if('A' <= str[i] && str[i] <= 'Z')
        {
            cout << str[i];
        }
    }
}