#include <iostream>

using namespace std;

int main()
{
    int g, p, t;
    cin >> g >> p >> t;

    if(g + p*t < g*p)
    {
        cout << 2;
    }
    else if(g + p*t > g*p)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}