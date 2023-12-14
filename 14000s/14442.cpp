#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

vector <vector <bool>> field;
int dp[11][1000][1000];
bool visited[11][1000][1000];
int n, m, k;

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    field.resize(n);
    for(int i = 0; i < n; i++)
    {
        field[i].resize(m);
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == '1')
            {
                field[i][j] = true;
            }
        }
    }
    fill(&dp[0][0][0], &dp[10][999][999], INT32_MAX);
    dp[0][0][0] = 1;
    visited[0][0][0] = true;

    // y, x, floor
    queue <array<int, 3>> bfs_queue;
    bfs_queue.push({0, 0, 0});
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    while(!bfs_queue.empty())
    {
        int curr_y = bfs_queue.front().at(0);
        int curr_x = bfs_queue.front().at(1);
        int floor = bfs_queue.front().at(2);
        bfs_queue.pop();

        if(curr_y == n-1 && curr_x == m-1)
        {
            cout << dp[floor][curr_y][curr_x];
            return 0;
        }

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];
            if(0 <= y && y < n && 0 <= x && x < m && !visited[floor][y][x] && floor <= k)
            {
                if(field[y][x] == true)
                {
                    if(floor != k && !visited[floor+1][y][x])
                    {
                        dp[floor+1][y][x] = min(dp[floor+1][y][x], dp[floor][curr_y][curr_x]+1);
                        bfs_queue.push({y, x, floor+1});
                        visited[floor+1][y][x] = true;
                    }
                }
                else
                {
                    dp[floor][y][x] = dp[floor][curr_y][curr_x]+1;
                    bfs_queue.push({y, x, floor});
                    visited[floor][y][x] = true;
                }
            }
        }
    }

    int result = INT32_MAX;
    for(int i = 0; i <= k; i++)
    {
        result = min(result, dp[i][n-1][m-1]);
    }
    
    if(result == INT32_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << result;
    }
}