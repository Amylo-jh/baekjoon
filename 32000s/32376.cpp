#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector <double> dist(n);
    for(int i = 0; i < n; i++)
    {
        double a, b;
        cin >> a >> b;
        dist[i] = sqrt(a*a + b*b);

    }
    sort(dist.begin(), dist.end());

    double max_accuracy = 0;
    for(int i = 0; i < n; i++)
    {
        double r_min = dist[i];
        double r_max = dist[i]+k;

        int count = 0;
        int lo = lower_bound(dist.begin(), dist.end(), r_min) - dist.begin();
        int hi = upper_bound(dist.begin(), dist.end(), r_max) - dist.begin();
        count = hi - lo;

        max_accuracy = max(max_accuracy, (double)count*100/n);
    }

    cout << fixed;
    cout.precision(10);
    cout << max_accuracy;
}