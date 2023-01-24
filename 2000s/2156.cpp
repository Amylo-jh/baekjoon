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

    vector <int> wine(n);
    vector <int> dp(n);

    for(int i = 0; i < n; i++)
    {
        cin >> wine[i];
    }

    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];

    for(int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i-3] + wine[i-1] + wine[i], max(dp[i-2] + wine[i], dp[i-1]));
    }

    cout << dp[n-1];
}