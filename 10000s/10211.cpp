#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        int arr[1001] = {0};
        int dp[1001] = {0};

        int num;
        int max_sum = INT32_MIN;
        cin >> num;

        for(int i = 1; i <= num; i++)
        {
            cin >> arr[i];
        }

        for(int i = 1; i <= num; i++)
        {
            dp[i] = arr[i];

            dp[i] = max(dp[i-1] + arr[i], dp[i]);
            max_sum = max(max_sum, dp[i]);
        }

        cout << max_sum << "\n";
    }
}