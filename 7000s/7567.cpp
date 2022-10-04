#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int length = 10;

    for(int i = 1; i < str.length(); i++)
    {
        if(str[i] == str[i-1])
        {
            length += 5;
        }
        else
        {
            length += 10;
        }
    }

    cout << length;
}