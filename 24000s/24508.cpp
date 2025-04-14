#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    long long t;
    cin >> n >> k >> t;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<>());

    long long answer = 0;
    int lo = 0;
    int hi = n-1;
    while(lo < hi)
    {
        if(arr[lo] + arr[hi] >= k)
        {
            answer += k - arr[lo];
            arr[hi] = arr[lo]+arr[hi]-k;
            if(arr[hi] == 0)
            {
                hi--;
            }
            lo++;
        }
        else if(arr[lo] + arr[hi] < k)
        {
            arr[lo] = arr[lo]+arr[hi];
            answer += arr[hi];
            hi--;
        }
    }

    if(arr[lo] % k != 0)
    {
        cout << "NO";
    }
    else
    {
        if(answer <= t)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
}