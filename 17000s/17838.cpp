#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string str;
        cin >> str;
        if(str.length() != 7)
        {
            cout << "0\n";
        }
        else if(str[0] == str[1] && str[2] == str[3] && str[5] == str[6]
        && str[0] == str[4] && str[2] == str[5] && str[1] != str[2])
        {
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
        }
    }
}