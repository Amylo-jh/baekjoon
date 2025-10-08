#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector <long long> arr(n+1);
    vector <long long> sum(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + arr[i];
    }

    while(q--)
    {
        long long x;
        cin >> x;
        int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        long long lo = sum[pos-1];
        long long hi = sum[n] - lo;
        long long lo_dist = (x * (pos-1)) - lo;
        long long hi_dist = hi - (x * (n - (pos-1)));
        cout << lo_dist + hi_dist << "\n";
    }
}