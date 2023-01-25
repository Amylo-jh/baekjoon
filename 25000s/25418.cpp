#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, k;
    cin >> a >> k;

    vector <int> dp(1000001);

    for(int i = 0; i < a; i++)
    {
        dp[i] = 1000000;
    }
    for(int i = a+1; i <= k; i++)
    {
        if(i % 2)
        {
            dp[i] = dp[i-1] + 1;
        }
        else
        {
            dp[i] = min(dp[i-1] + 1, dp[i/2] + 1);
        }
    }

    cout << dp[k];
}