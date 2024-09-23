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

    vector <int> arr(n+1);
    vector <int> dp(n+1);
    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i] = min(min(i, arr[i]), dp[i-1]+1);
        answer = max(answer, dp[i]);
    }

    cout << answer;
}