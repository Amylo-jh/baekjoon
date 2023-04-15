#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector <vector <vector <int>>> dp(n);
    vector <vector <int>> space(n);
    for(int i = 0; i < n; i++)
    {
        dp[i].resize(m);
        space[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            dp[i][j].resize(3);
            cin >> space[i][j];
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            dp[0][i][j] = space[0][i];
        }
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(j == 0)
            {
                dp[i][j][0] = min(dp[i-1][j+1][1], dp[i-1][j+1][2]) + space[i][j];
                dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + space[i][j];
                dp[i][j][2] = INT32_MAX;
            }
            else if(j == m-1)
            {
                dp[i][j][0] = INT32_MAX;
                dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + space[i][j];
                dp[i][j][2] = min(dp[i-1][j-1][0], dp[i-1][j-1][1]) + space[i][j];
            }
            else
            {
                dp[i][j][0] = min(dp[i-1][j+1][1], dp[i-1][j+1][2]) + space[i][j];
                dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + space[i][j];
                dp[i][j][2] = min(dp[i-1][j-1][0], dp[i-1][j-1][1]) + space[i][j];
            }
        }
    }

    int min_cost = INT32_MAX;
    for(int j = 0; j < m; j++)
    {
        for(int k = 0; k < 3; k++)
        {
            min_cost = min(min_cost, dp[n-1][j][k]);
        }
    }
    cout << min_cost;
}