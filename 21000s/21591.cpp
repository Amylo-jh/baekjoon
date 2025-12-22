#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a -= 2;
    b -= 2;
    if(a >= c && b >= d)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}