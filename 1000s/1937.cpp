#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int>> area;
vector <vector <int>> dp;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n;

int init_dfs(int init_y, int init_x)
{    
    if(dp[init_y][init_x])
    {
        return dp[init_y][init_x];
    }

    dp[init_y][init_x] = 1;
    for(int i = 0; i < 4; i++)
    {
        int y = init_y + dy[i];
        int x = init_x + dx[i];

        if(0 <= y && y < n && 0 <= x && x < n)
        {
            if(area[y][x] > area[init_y][init_x])
            {
                dp[init_y][init_x] = max(init_dfs(y, x) + 1, dp[init_y][init_x]);
            }
        }
    }

    return dp[init_y][init_x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    area.resize(n);
    dp.resize(n);
    for(int i = 0; i < n; i++)
    {
        area[i].resize(n);
        dp[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            cin >> area[i][j];
        }
    }

    int max_move = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            init_dfs(i, j);
            max_move = max(max_move, dp[i][j]);
        }
    }

    cout << max_move;
}