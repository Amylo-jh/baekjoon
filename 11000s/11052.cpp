#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    vector<int> price(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; i + j <= n; j++)
        {
            dp[i+j] = max(dp[i+j], dp[i] + price[j]);
        }
    }
    cout << dp[n];
}