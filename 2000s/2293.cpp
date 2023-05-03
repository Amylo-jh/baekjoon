#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector <int> coin;
    vector <int> dp(k+1);
    coin.reserve(n);
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(temp <= k)
        {
            coin.push_back(temp);
        }
    }

    dp[0] = 1;
    for(int i = 0; i < coin.size(); i++)
    {
        for(int j = coin[i]; j <= k; j++)
        {
            dp[j] = dp[j - coin[i]] + dp[j];
        }
    }

    cout << dp[k];
}