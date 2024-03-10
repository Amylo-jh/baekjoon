#include <iostream>

using namespace std;

int main()
{
    double a, m, n;
    cin >> a >> m >> n;

    double _1time = min(m, n) / a * 2;
    double _2time = max(min(m, n), max(m, n) / a);
    
    cout.precision(20);
    cout << min(_1time, _2time);
}