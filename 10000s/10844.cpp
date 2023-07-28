#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <vector <long long>> dp(101);
    for(int i = 0; i <= 100; i++)
    {
        dp[i].resize(10);
    }
    dp[1] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for(int i = 2; i <= 100; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i-1][j+1];
            }
            else if(j == 9)
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            }
            dp[i][j] %= 1000000000;
        }
    }

    int n;
    cin >> n;

    long long answer = 0;
    for(int i = 0; i < 10; i++)
    {
        answer += dp[n][i];
        answer %= 1000000000;
    }
    cout << answer;
}