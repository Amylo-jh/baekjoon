#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <long long> dp = {0, 1, 2, 4};
    dp.reserve(1000001);
    for(int i = 4; i <= 1000000; i++)
    {
        long long next = dp[i-1] + dp[i-2] + dp[i-3];
        next %= 1000000009;
        dp.push_back(next);
    }

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int query;
        cin >> query;
        cout << dp[query] << "\n";
    }
}