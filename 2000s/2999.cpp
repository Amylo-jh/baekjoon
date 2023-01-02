#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int n = str.length();

    int r = 1;
    int c = 0;
    for(int i = 1; i < n; i++)
    {
        if(n % i == 0)
        {
            if(i <= n / i)
            {
                r = i;
                c = n / i;
            }
            else
            {
                break;
            }
        }
    }

    for(int j = 0; j < r; j++)
    {
        for(int i = 0; i < n/r; i++)
        {
            cout << str[(i*r) + j];
        }
    }
}