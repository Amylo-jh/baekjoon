#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int max_value = 100000000;
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector <int> dp(n+1);
    dp.assign(n+1, max_value);
    dp[0] = 0;

    for(int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        for(int j = start; j <= end; j++)
        {
            dp[j] = -1;
        }
    }

    for(int i = 0; i <= n; i++)
    {
        if(dp[i] == -1)
        {
            continue;
        }

        if(i - a >= 0)
        {
            if(dp[i-a] != -1)
            {
                dp[i] = min(dp[i-a]+1, dp[i]); 
            }
        }
        if(i - b >= 0)
        {
            if(dp[i-b] != -1)
            {
                dp[i] = min(dp[i-b]+1, dp[i]);
            }
        }
    }

    if(dp[n] != max_value)
    {
        cout << dp[n];
    }
    else
    {
        cout << -1;
    }
}