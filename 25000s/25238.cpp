#include <iostream>

using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;
    b = (100 - b) * 0.01;

    a *= b;
    if(a >= 100)
    {
        cout << 0;
    }
    else
    {
        cout << 1;
    }
}