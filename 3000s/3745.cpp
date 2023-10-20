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
    while(cin >> n)
    {
        vector <int> arr(n);
        vector <int> dp;
        int idx = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        dp.push_back(arr[0]);
        for(int i = 1; i < n; i++)
        {
            if(dp[idx] < arr[i])
            {
                dp.push_back(arr[i]);
                idx++;
            }
            else
            {
                int index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
                dp[index] = arr[i];
            }
        }
        cout << dp.size() << "\n";
    }
}