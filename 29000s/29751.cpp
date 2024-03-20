#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;

    cout.setf(ios::showpoint);
    cout << fixed;
    cout.precision(1);
    cout << a* b / 2;
}