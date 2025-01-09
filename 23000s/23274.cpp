#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int sx1, sy1, sx2, sy2, ex1, ey1, ex2, ey2;
    cin >> sx1 >> sy1 >> sx2 >> sy2 >> ex1 >> ey1 >> ex2 >> ey2;

    double a = 0, b = 0;
    a = sqrt(pow(sx1 - sx2, 2) + pow(sy1 - sy2, 2));
    b = sqrt(pow(ex1 - ex2, 2) + pow(ey1 - ey2, 2));
    cout.precision(10);
    cout << max(a, b);
}