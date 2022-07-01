#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int total_time = 0;

    if(a < 0)
    {
        total_time = c * -1 * a + d;
        total_time = total_time + b * e;
    }
    else if(a > 0)
    {
        total_time = (b - a) * e;
    }

    cout << total_time;
}