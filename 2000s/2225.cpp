#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> dp;

int main()
{
    int n, k;
    cin >> n >> k;

    dp.resize(k);
    dp[0].resize(n+1);
    dp[0].assign(n+1, 1);
    for(int i = 1; i < k; i++)
    {
        dp[i].resize(n+1);
        dp[i][0] = 1;
        for(int j = 1; j < n+1; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= 1000000000;
        }
    }

    cout << dp[k-1][n];
}