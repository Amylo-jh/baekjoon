#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b;
    string d;
    while(1)
    {
        cin >> a >> d >> b;
        if(a == 0 && b == 0 && d == "W")
        {
            break;
        }
        if(d == "W")
        {
            a -= b;
            if(a < -200)
            {
                cout << "Not allowed\n";
            }
            else
            {
                cout << a << "\n";
            }
        }
        else
        {
            a += b;
            cout << a << "\n";
        }
    }
}