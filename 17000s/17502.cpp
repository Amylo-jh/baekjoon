#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string str;
    string nstr;
    cin >> n >> str;

    nstr = str;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == '?')
        {
            if(str[n-i-1] == '?')
            {
                nstr[i] = 'a';
                nstr[n-i-1] = 'a';
            }
            else
            {
                nstr[i] = str[n-i-1];
            }
        }
    }

    cout << nstr;
}