#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    regex re("(pi|ka|chu)+");
    
    if(regex_match(str, re))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}