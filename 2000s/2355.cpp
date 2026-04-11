#include <iostream>

using namespace std;

int main()
{
    double a, b, sum = 0;
    cin >> a >> b;
    cout << int(((a+b)/2) * (abs(a-b)+1));
}