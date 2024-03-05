#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector <int> arr(n*n);
    long long sum = 0;
    for(int i = 0; i < n*n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sum++;
    sum /= 2;
    

    sort(arr.begin(), arr.end());
    int lo = 0;
    int hi = arr[n*n-1];
    int result = 0;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        long long curr_sum = 0;
        for(int i = 0; i < n*n; i++)
        {
            curr_sum += min(arr[i], mid);
        }

        if(curr_sum < sum)
        {
            lo = mid+1;
        }
        else
        {
            result = mid;
            hi = mid-1;
        }
    }

    cout << result;
}