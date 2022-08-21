#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double k, d1, d2;
    cin >> k >> d1 >> d2;

    d1 = (d1 - d2) / 2;

    double height = k*k - d1*d1;
    cout << height;
}