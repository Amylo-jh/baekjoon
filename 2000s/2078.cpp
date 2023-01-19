#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int l = 0;
    int r = 0;

    while(a != 1 && b != 1)
    {
        if(a < b)
        {
            r += b / a;
            b -= a * (b / a);
        }
        else
        {
            l += a / b;
            a -= b * (a / b);
        }
    }

    if(a != 1)
    {
        l += a-1;
    }
    if(b != 1)
    {
        r += b-1;
    }

    cout << l << " " << r;
}