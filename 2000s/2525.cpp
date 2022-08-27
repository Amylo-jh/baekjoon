#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int total_time = a*60 + b + c;

    a = total_time / 60;
    a = a % 24;
    b = total_time % 60;

    cout << a << " " << b;
}