#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    regex e("\\bda+dd?(i|y)\\b");
    string str;
    while(cin >> str)
    {
        if(regex_match(str, e))
        {
            cout << "She called me!!!\n";
        }
        else
        {
            cout << "Cooing\n";
        }
    }
}