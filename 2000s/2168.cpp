#include <iostream>
#include <cmath>

using namespace std;

int gcd (int x, int y)
{
    if(y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x % y);
    }
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << a + b - gcd(a, b);
}