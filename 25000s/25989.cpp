#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    long double e;
    cin >> n >> e;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        long double r;
        cin >> r;
        if(e > 2.0L*r)
        {
            sum++;
            continue;
        }
        double result = M_PI / (asin(min(1.0L, e / (2.0*r))));
        sum += floor(result);
    }

    cout << sum;
}