#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a1, p1, r2, p2;
    cin >> a1 >> p1 >> r2 >> p2;
    r2 = r2 * r2 * M_PI;
    a1 = a1 / p1;
    r2 = r2 / p2;
    if (a1 > r2)
    {
        cout << "Slice of pizza";
    }
    else
    {
        cout << "Whole pizza";
    }
}