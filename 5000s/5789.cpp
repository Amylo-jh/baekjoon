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

        int len = str.length() / 2;

        if(str[len] == str[len-1])
        {
            cout << "Do-it\n";
        }
        else
        {
            cout << "Do-it-Not\n";
        }
    }
}