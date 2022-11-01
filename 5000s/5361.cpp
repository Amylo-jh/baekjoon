#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    cout << fixed;
    cout.precision(2);
    for(int q = 0; q < tc; q++)
    {
        long long a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        cout << "$" << a*350.34 + b*230.90 + c*190.55 + d*125.30 + e*180.90 << "\n";
    }
}