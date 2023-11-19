#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // memory, cost;
    vector <pair <int, int>> app(n+1);
    vector <vector <int>> dp(2);
    
    int total_size = 0;
    int max_cost = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> app[i].first;
        total_size += app[i].first;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> app[i].second;
        max_cost += app[i].second;
    }
    dp[0].resize(max_cost+1);
    dp[1].resize(max_cost+1);

    for(int i = 1; i <= n; i++)
    {
        for(int w = 0; w <= max_cost; w++)
        {
            if(app[i].second <= w)
            {
                dp[1][w] = max(dp[0][w], app[i].first + dp[0][w-app[i].second]);
            }
            else
            {
                dp[1][w] = dp[0][w];
            }
        }   
        dp[0] = dp[1];
    }

    int result = 0;
    for(int i = 0; i <= max_cost; i++)
    {
        if(dp[1][i] >= m)
        {
            result = i;
            break;
        }
    }

    cout << result;
}