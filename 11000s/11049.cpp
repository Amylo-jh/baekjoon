#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <pair <int, int>> arr(n+1);
    vector <vector <int>> dp(n+1, vector <int> (n+1, 2e9));

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        dp[i][i] = 0;
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j+i <= n; j++)
        {
            for(int k = j; k < i+j; k++)
            {
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + arr[j].first * arr[k].second * arr[i+j].second);
            }
        }
    }

    cout << dp[1][n] << '\n';
}