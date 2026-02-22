#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<pair<int, int>> dp(41);
    dp[1] = {1, 0};
    dp[2] = {1, 0};
    for (int i = 3; i <= 40; i++)
    {
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + 1;
    }
    int n;
    cin >> n;
    cout << dp[n].first << " " << dp[n].second;
}