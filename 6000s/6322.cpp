#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    for (int tc = 1;; tc++)
    {
        double a, b, c;
        cin >> a >> b >> c;
        cout << fixed;
        cout.precision(3);
        if (a == 0 && b == 0 && c == 0)
        {
            break;
        }
        cout << "Triangle #" << tc << "\n";
        if (a == -1)
        {
            if (c * c - b * b > 0)
            {
                cout << "a = " << sqrt(c * c - b * b) << "\n\n";
            }
            else
            {
                cout << "Impossible.\n\n";
            }
        }
        else if (b == -1)
        {
            if (c * c - a * a > 0)
            {
                cout << "b = " << sqrt(c * c - a * a) << "\n\n";
            }
            else
            {
                cout << "Impossible.\n\n";
            }
        }
        else
        {
            cout << "c = " << sqrt(a * a + b * b) << "\n\n";
        }
    }
}