#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <pair <int, int>> task(n+1);
    vector <int> dp(n+2);
    for(int i = 1; i <= n; i++)
    {
        cin >> task[i].first >> task[i].second;
    }

    for(int i = n; i > 0; i--)
    {
        if(i + task[i].first <= n+1)
        {
            dp[i] = max(dp[i+1], dp[i+task[i].first] + task[i].second);
        }
        else
        {
            dp[i] = dp[i+1];
        }
    }

    int max_value = 0;
    for(int i = 1; i <= n; i++)
    {
        max_value = max(max_value, dp[i]);
    }
    cout << max_value;
}