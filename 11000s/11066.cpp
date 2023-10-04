#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;
    while(tc--)
    {
        int k;
        cin >> k;
        vector <vector <int>> dp(k+1);
        vector <int> arr(k+1);
        vector <int> sum(k+1);
        for(int i = 1; i <= k; i++)
        {
            dp[i].resize(k+1);
            cin >> arr[i];
        }
        for(int i = 1; i <= k; i++)
        {
            sum[i] = sum[i-1] + arr[i];
        }

        for(int i = 1; i <= k; i++)
        {
            for(int j = 1; j+i <= k; j++)
            {
                dp[j][j+i] = INT32_MAX;
                for(int mid = j; mid < i+j; mid++)
                {
                    int mid_dp = dp[j][mid]+dp[mid+1][i+j];
                    int pre_sum = sum[i+j] - sum[j-1];
                    dp[j][i+j] = min(dp[j][i+j], mid_dp+pre_sum);
                }
            }
        }

        cout << dp[1][k] << "\n";  
    }
}