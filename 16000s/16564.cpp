#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int lo = arr[0], hi = lo+k, mid, ans = 0;
    while(lo <= hi)
    {
        mid = (lo+hi)/2;
        long long sum = 0;
        for(int i = 0; i < n && arr[i] < mid; i++)
        {
            sum += mid - arr[i];
        }

        if(sum <= k)
        {
            lo = mid+1;
            ans = max(ans, mid);
        }
        else
        {
            hi = mid-1;
        }
    }
    cout << ans;
}