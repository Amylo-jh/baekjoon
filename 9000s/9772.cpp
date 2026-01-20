#include <iostream>

using namespace std;

int main()
{
    double a, b;
    while(cin >> a >> b)
    {
        if(a == 0 || b == 0)
        {
            cout << "AXIS";
        }
        else if(a > 0 && b > 0)
        {
            cout << "Q1";
        }
        else if(a < 0 && b > 0)
        {
            cout << "Q2";
        }
        else if(a > 0 && b < 0)
        {
            cout << "Q4";
        }
        else if(a < 0 && b < 0)
        {
            cout << "Q3";
        }
        cout << "\n";
    }

}