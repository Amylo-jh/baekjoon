#include <iostream>

using namespace std;

int rev(int a)
{
    int b = 0;
    while(a)
    {
        b *= 10;
        b += a%10;
        a /= 10;
    }

    return b;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << rev(rev(a) + rev(b));
}