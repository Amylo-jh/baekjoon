#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    int n = 0;
    cin >> a >> b >> c;

    if(b > c)
    {
        cout << -1;
    }
    else
    {
        if(a == 0)
        {
            if(c-b == 0)
            {
                cout << -1;
            }
            else
            {
                cout << 1;
            }
        }
        else if(c-b == 0)
        {
            cout << -1;
        }
        else
        {
            n = a / (c-b);
            n++;
            cout << n;
        }
    }
}