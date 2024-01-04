#include <iostream>
#include <vector>

using namespace std;

vector <int> train;
vector <int> sum;
vector <vector <int>> dp;

int main()
{
    int n, k;
    cin >> n;
    train.resize(n+1);
    sum.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> train[i];
        sum[i] = train[i] + sum[i-1];
    }
    dp.resize(3);
    for(int i = 0; i < 3; i++)
    {
        dp[i].resize(n+1);
    }

    cin >> k;
    for(int i = 0; i < 3; i++)
    {
        for(int j = i*k; j <= n; j++)
        {
            if(i > 0 && j-k >= 0)
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-k] + sum[j]-sum[j-k]);
            }
            else if(j-k >= 0)
            {
                dp[i][j] = max(dp[i][j-1], sum[j] - sum[j-k]);
            }
        }
    }

    cout << dp[2][n];
}