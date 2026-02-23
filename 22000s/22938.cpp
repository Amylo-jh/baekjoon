#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    if ((abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2)) < (r1 + r2) * (r1 + r2))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}