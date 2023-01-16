#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <vector <int>> color(n);

    for(int i = 0; i < n; i++)
    {
        color[i].resize(3);
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }

    vector <vector <int>> dp(n);
    dp[0].resize(3);
    dp[0][0] = color[0][0];
    dp[0][1] = color[0][1];
    dp[0][2] = color[0][2];

    for(int i = 1; i < n; i++)
    {
        dp[i].resize(3);
        
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + color[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + color[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + color[i][2];
    }

    cout << min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
}