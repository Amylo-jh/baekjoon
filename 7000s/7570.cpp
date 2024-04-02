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
    vector <int> v(n);
    vector <int> dp(n+1);
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        count = max(count, dp[v[i]] = dp[v[i]-1] + 1);
    }

    cout << n-count << "\n";
}