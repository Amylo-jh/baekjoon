#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m;
vector <vector <int>> dp;
vector <vector <int>> area;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
    

int dfs(int curr_y, int curr_x)
{
    if(curr_y == n-1 && curr_x == m-1)
    {
        return 1;
    }

    if(dp[curr_y][curr_x] != -1)
    {
        return dp[curr_y][curr_x];
    }
    dp[curr_y][curr_x] = 0; //visit 처리

    for(int i = 0; i < 4; i++)
    {
        int y = curr_y + dy[i];
        int x = curr_x + dx[i];

        if(0 <= y && y < n && 0 <= x && x < m)
        {
            if(area[curr_y][curr_x] > area[y][x])
            {
                dp[curr_y][curr_x] += dfs(y, x);
            }
        }
    }

    return dp[curr_y][curr_x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    area.resize(n);
    dp.resize(n);
    for(int i = 0; i < n; i++)
    {
        area[i].resize(m);
        dp[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            cin >> area[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0);
}
