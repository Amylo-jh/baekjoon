#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if(a == b && b == c)
    {
        cout << 10000 + a * 1000;
    }
    else if(a == b || b == c)
    {
        cout << 1000 + b * 100;
    }
    else if(a == c)
    {
        cout << 1000 + a * 100;
    }
    else
    {
        cout << max(a, max(b, c)) * 100;
    }
}