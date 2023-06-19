#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <long long> dp(31);
    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 11;
    dp[6] = 41;

    for(int i = 8; i <= 30; i = i+2)
    {
        dp[i] = dp[i-2] * 3;
        for(int j = 4; j <= i; j = j+2)
        {
            dp[i] += dp[i-j]*2;
        }
    }

    int n;
    cin >> n;
    cout << dp[n];
}