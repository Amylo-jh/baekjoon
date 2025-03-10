#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> arr;
vector <int> dp;

int solve(int i)
{
    if(i >= n)
    {
        return 0;
    }
    else if(dp[i])
    {
        return dp[i];
    }

    return dp[i] = max(arr[i] + solve(i+2), solve(i+1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.resize(n);
    dp.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i] >> arr[i] >> arr[i];
    }

    solve(0);
    cout << dp[0];
}