#include <iostream>

using namespace std;

int main()
{
    long long n, m, t, s;
    long long min_time = 0;
    cin >> n >> m >> t >> s;

    long long time = (n/8)*s + n;
    if(n%8 == 0)
    {
        time -= s;
    }

    min_time = time;
    time = t + (m/8)*(s+2*t) + m;
    if(m%8 == 0)
    {
        time -= s+2*t;
    }

    if(min_time > time)
    {
        cout << "Dok\n";
        cout << time;
    }
    else
    {
        cout << "Zip\n";
        cout << min_time;
    }
}