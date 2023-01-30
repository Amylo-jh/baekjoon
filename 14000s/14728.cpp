#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    //time, score;
    vector <pair <int, int>> subject(n+1);
    vector <int> dp(t+1);
    vector <int> dp2(t+1);

    for(int i = 1; i <= n; i++)
    {
        cin >> subject[i].first >> subject[i].second;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= t; j++)
        {
            if(j >= subject[i].first)
            {
                dp2[j] = max(dp[j], dp[j-subject[i].first] + subject[i].second);
            }
        }
        dp = dp2;
    }

    cout << dp2[t];
}