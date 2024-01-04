#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    double pi = 3.14159265358979323846;

    cout << fixed;
    cout.precision(7);
    cout << n * n * pi << "\n";
    cout << n * n * 2;
}