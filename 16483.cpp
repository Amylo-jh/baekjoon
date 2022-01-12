#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double t;
    cin >> t;
    t = t/2;
    t = t* t;
    t = round(t);
    cout << (int)t;
}