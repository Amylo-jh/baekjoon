#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;

    int pos = 0;

    for(int i = 1; i <= n; i++)
    {
        int digit = log10(i)+1;

        if(pos + digit > str.size())
        {
            cout << i;
            break;
        }
        string s = str.substr(pos, digit);
        int num = stoi(s);

        if(num != i)
        {
            cout << i;
            break;
        }
        pos += digit;
    }
}