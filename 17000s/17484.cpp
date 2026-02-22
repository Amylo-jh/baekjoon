#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, 1e9)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int j = 0; j < m; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            dp[0][j][k] = arr[0][j];
        }
    }

    int dx[3] = {-1, 0, 1};
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int nx = j + dx[k];
                if (nx < 0 || m <= nx)
                {
                    continue;
                }
                for (int t = 0; t < 3; t++)
                {
                    if (k == t)
                    {
                        continue;
                    }
                    dp[i][j][k] = min(dp[i - 1][nx][t] + arr[i][j], dp[i][j][k]);
                }
            }
        }
    }
    int answer = INT32_MAX;
    for (int j = 0; j < m; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            answer = min(answer, dp[n - 1][j][k]);
        }
    }
    cout << answer;
}