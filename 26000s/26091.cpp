#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int lo = 0, hi = n - 1, count = 0;
    while (lo < hi)
    {
        if (arr[lo] + arr[hi] >= m)
        {
            count++;
            lo++;
            hi--;
        }
        else
        {
            lo++;
        }
    }
    cout << count;
}