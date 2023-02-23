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

    vector <int> dp[2];
    dp[0].resize(n);
    dp[1].resize(n);

    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dp[0][0] = arr[0];
    dp[1][0] = arr[0];
    int ans = arr[0];
    for(int i = 1; i < n; i++)
    {
        dp[0][i] = max(dp[0][i-1] + arr[i], arr[i]);
        dp[1][i] = max(dp[0][i-1], dp[1][i-1] + arr[i]);
        ans = max(ans, max(dp[0][i], dp[1][i]));
    }

    cout << ans;
}