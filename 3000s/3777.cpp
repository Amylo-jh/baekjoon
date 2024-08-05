#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <long long> dp(1001, 0);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i = 4; i <= 1000; i++)
    {
        dp[i] = dp[i-1] + dp[i-2] * 2;
    }

    int n;
    while(cin >> n)
    {
        cout << dp[n] << '\n';
    }
}