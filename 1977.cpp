#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int m, n;
    int total = 0;
    int i;
    int sqrt_m, sqrt_n;
    int minimum;

    cin >> m >> n;

    sqrt_m = sqrt(m);
    sqrt_n = sqrt(n);

    if (sqrt_m == sqrt_n)
    {
        cout << "-1";
        return 0;
    }

    for (i = sqrt_n; i >=sqrt_m; i--)
    {
        if(m <= i*i && i*i <= n)
        {
            total = total + i*i;
            minimum = i*i;
        }
    }

    cout << total << "\n" << minimum;;
}