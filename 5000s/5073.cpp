#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    int m;
    while(1)
    {
        cin >> a >> b >> c;
        m = max(a, max(b, c));
        if(!(a + b + c))
        {
            break;
        }

        if(a + b + c - m <= m)
        {
            cout << "Invalid\n";
            continue;
        }
        
        if(a == b && b == c)
        {
            cout << "Equilateral\n";
        }
        else if(a == b || b == c || c == a)
        {
            cout << "Isosceles\n";
        }
        else
        {
            cout << "Scalene\n";
        }
    }
}