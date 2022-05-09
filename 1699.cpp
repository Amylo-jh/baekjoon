#include <iostream>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) < (b)) ? (b) : (a))

using namespace std;

int main()
{
    int dp[100001] = {0};
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        dp[i] = i;
        for(int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i-(j*j)] + 1);
        }
    }

    cout << dp[n];
}