#include <iostream>

using namespace std;

int main()
{
    double n, p;
    cin >> n >> p;
    cout.precision(20);
    cout << (100 / (100 - p) - 1) * 100;
}