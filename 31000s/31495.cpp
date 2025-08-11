#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int n = str.length();

    if(n < 2)
    {
        cout << "CE";
    }
    if(str[0] == '"' && str[n-1] == '"')
    {
        if(n == 2)
        {
            cout << "CE";
            return 0;
        }
        for(int i = 1; i < n-1; i++)
        {
            cout << str[i];
        }
    }
    else
    {
        cout << "CE";
    }
}