#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0, t1, t2;
    vector <pair <int, int>> player;
    while(cin >> t1 >> t2)
    {
        player.push_back({t1, t2});
        n++;
    }
    vector <vector <int>> dp(16, vector <int>(16, 0));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 15; j >= 0; j--)
        {
            for(int k = 15; k >= 0; k--)
            {
                if(j)
                {
                    dp[j][k] = max(dp[j][k], dp[j-1][k] + player[i].first);
                }
                if(k)
                {
                    dp[j][k] = max(dp[j][k], dp[j][k-1] + player[i].second);
                }
            }
        }
    }
    cout << dp[15][15];
}