#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long hi = INT32_MAX;
    long long lo = 0;
    long long mid;
    while(lo <= hi)
    {
        mid = (hi + lo) / 2;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            cnt += arr[i] / mid;
        }

        if(cnt >= k)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << hi;
}