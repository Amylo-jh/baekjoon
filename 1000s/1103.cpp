#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector <vector <int>> arr;
vector <vector <bool>> visited;
vector <vector <int>> dp;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int dfs(int cy, int cx)
{
    if(0 <= cy && cy < n && 0 <= cx && cx < m && arr[cy][cx])
    {
        if(visited[cy][cx])
        {
            cout << -1;
            exit(0);
        }
        if(dp[cy][cx] != -1)
        {
            return dp[cy][cx];
        }

        visited[cy][cx] = true;
        dp[cy][cx] = 0;

        for(int i = 0; i < 4; i++)
        {
            int y = cy + dy[i]*arr[cy][cx];
            int x = cx + dx[i]*arr[cy][cx];
            dp[cy][cx] = max(dp[cy][cx], dfs(y, x) + 1);
        }

        visited[cy][cx] = false;
        return dp[cy][cx];
    }
    return 0;
}

int main()
{
    cin >> n >> m;

    arr.resize(n);
    visited.resize(n);
    dp.resize(n);
    for(int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        visited[i].resize(m);
        dp[i].resize(m);
        dp[i].assign(m, -1);
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == 'H')
            {
                arr[i][j] = 0;
            }
            else
            {
                arr[i][j] = str[j] - '0';
            }
        }
    }

    cout << dfs(0, 0);
}