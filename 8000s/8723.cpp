#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && b == c)
    {
        cout << 2;
    }
    else if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
    {
        cout << 1;
    }
    else
    {
        int max_value = max({a, b, c});
        if(a+b+c - max_value <= max_value)
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
    }
}