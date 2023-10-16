#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    vector <int> dp;
    int index = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dp.push_back(arr[0]);
    for(int i = 1; i < n; i++)
    {
        if(dp[index] < arr[i])
        {
            dp.push_back(arr[i]);
            index++;
        }
        else
        {
            int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[idx] = arr[i];
        }
    }

    cout << n - dp.size();
}