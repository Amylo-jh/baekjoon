#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, a = 0, b = 0;
    string str;
    cin >> n >> str;
    for(int i = 0; i < n; i++)
    {
        int c = str[i] - '0';
        if(c % 2)
        {
            b++;
        }
        else
        {
            a++;
        }
    }

    if(a == b)
    {
        cout << -1;
    }
    else if(a > b)
    {
        cout << 0;
    }
    else if(a < b)
    {
        cout << 1;
    }
}