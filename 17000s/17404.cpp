#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int max_val = 10000000;
    int n;
    cin >> n;

    vector <vector <int>> house(n);
    vector <vector <vector <int>>> dp(3);
    dp[0].resize(n);
    dp[1].resize(n);
    dp[2].resize(n);
    for(int i = 0; i < n; i++)
    {
        // dp initialize
        for(int j = 0; j < 3; j++)
        {
            dp[j][i].resize(3);
            for(int k = 0; k < 3; k++)
            {
                dp[j][i][k] = max_val;
            }
        }

        // house initialize
        house[i].resize(3);
        for(int j = 0; j < 3; j++)
        {
            cin >> house[i][j];
        }
    }

    dp[0][0] = house[0];
    dp[1][0] = house[0];
    dp[2][0] = house[0];

    dp[0][0][1] = max_val;
    dp[0][0][2] = max_val;
    dp[1][0][0] = max_val;
    dp[1][0][2] = max_val;
    dp[2][0][0] = max_val;
    dp[2][0][1] = max_val;

    for(int k = 0; k < 3; k++)
    {
        for(int i = 1; i < n; i++)
        {
            dp[k][i][0] = min(dp[k][i-1][1] + house[i][0], dp[k][i-1][2] + house[i][0]);
            dp[k][i][1] = min(dp[k][i-1][0] + house[i][1], dp[k][i-1][2] + house[i][1]);
            dp[k][i][2] = min(dp[k][i-1][0] + house[i][2], dp[k][i-1][1] + house[i][2]);
        }
    }

    for(int i = 0; i < 3; i++)
    {
        dp[i][n-1][i] = max_val;
    }
    
    int result = max_val;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            result =min(result, dp[i][n-1][j]);
        }
    }

    cout << result;
}