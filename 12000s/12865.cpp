#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    //weight, value;
    vector <pair <int, int>> item(n+1);
    vector <vector <int>> dp(n+1);
    dp[0].resize(k+1);

    for(int i = 1; i <= n; i++)
    {
        cin >> item[i].first >> item[i].second;
        dp[i].resize(k+1);
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int w = 1; w <= k; w++)
        {
            if(item[i].first <= w)
            {
                if( (item[i].second + dp[i-1][w - item[i].first]) > dp[i-1][w] )
                {
                    dp[i][w] = item[i].second + dp[i-1][w - item[i].first];
                }
                else
                {
                    dp[i][w] = dp[i-1][w];
                }
            }
            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    cout << dp[n][k];
}