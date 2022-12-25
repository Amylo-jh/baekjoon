#include <iostream>

using namespace std;

int main()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long temp_b = b;
    long long temp_d = d;
    while(temp_b)
    {
        temp_b /= 10;
        a *= 10;
    }
    while (temp_d)
    {
        temp_d /= 10;
        c *= 10;
    }
    cout << a + b + c + d;
}