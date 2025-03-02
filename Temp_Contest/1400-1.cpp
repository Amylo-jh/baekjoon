#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b, a_lower, b_lower;
    cin >> a >> b;

    if(b == "null")
    {
        b = "";
    }
    for(char c : a)
    {
        a_lower.push_back(tolower(c));
    }
    for(char c : b)
    {
        b_lower.push_back(tolower(c));
    }

    if(a == "null")
    {
        cout << "NullPointerException\n";
        cout << "NullPointerException";
        return 0;
    }

    if(a == b)
    {
        cout << "true\n";
        cout << "true";
    }
    else
    {
        cout << "false\n";
        if(a_lower == b_lower)
        {
            cout << "true";
        }
        else
        {
            cout << "false";
        }
    }
}