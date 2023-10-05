#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> m >> n;
    vector <vector <int>> arr(m);
    vector <vector <int>> dp(m);
    for(int i = 0; i < m; i++)
    {
        arr[i].resize(n);
        dp[i].resize(n);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[j][i];
        }
    }

    dp[0] = arr[0];
    for(int i = 1; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(j == k)
                {
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + arr[i][j]/2);
                }
                else
                {
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + arr[i][j]);
                }
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        answer = max(answer, dp[m-1][i]);
    }

    cout << answer;
}