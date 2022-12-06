#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <vector <int>> dp(1001);

    for(int i = 0; i <= 1000; i++)
    {
        dp[i].resize(10);
    }

    for(int i = 0; i < 10; i++)
    {
        dp[0][i] = 1;
    }

    for(int i = 1; i <= 1000; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            for(int k = j; k < 10; k++)
            {
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= 10007;
            }
        }
    }

    int n;
    cin >> n;
    cout << dp[n][0];
}