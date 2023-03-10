#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n, s, t;
        cin >> n >> s >> t;
        vector <int> dp(n+1);
        dp[1] = s;

        for(int i = 2; i <= n; i++)
        {
            dp[i] = dp[i-1] + s;
            if(i % 2 == 0)
            {
                dp[i] = min(dp[i], dp[i/2] + t);
            }            
        }

        cout << dp[n] << "\n";
    }
}