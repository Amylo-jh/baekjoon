#include <iostream>

using namespace std;

int main()
{
    double a, b;
    double pi = 3.141592;
    cin >> a >> b;

    cout.precision(10);
    cout << a*2 + b*2*pi;
}