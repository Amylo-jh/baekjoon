#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b ,c;
    cin >> a >> b >> c;
    double result = a * max(b, c) / min(b, c);
    result = floor(result);
    cout << fixed;
    cout.precision(0);
    cout << result;
}