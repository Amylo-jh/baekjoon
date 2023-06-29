#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector <vector <int>> area;
vector <vector <int>> visited;

void reset_visited()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
}

int check_ice()
{
    int count = 0;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    queue <pair <int, int>> bfs_queue;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(area[i][j] && !visited[i][j])
            {
                count++;
                bfs_queue.push({i, j});
                visited[i][j] = true;
                while(!bfs_queue.empty())
                {
                    int curr_y = bfs_queue.front().first;
                    int curr_x = bfs_queue.front().second;
                    bfs_queue.pop();

                    for(int i = 0; i < 4; i++)
                    {
                        int y = curr_y + dy[i];
                        int x = curr_x + dx[i];
                        if(area[y][x] && !visited[y][x])
                        {
                            visited[y][x] = true;
                            bfs_queue.push({y, x});
                        }
                    }
                }
            }
        }
    }

    reset_visited();
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue <pair <pair <int, int>, int>> ocean;
    queue <pair <int, int>> ice;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    
    cin >> n >> m;
    area.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        area[i].resize(m);
        visited[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            cin >> area[i][j];
            if(area[i][j])
            {
                ice.push({i, j});
            }
        }
    }

    int year = 0;
    while(!ice.empty())
    {
        int curr_y = ice.front().first;
        int curr_x = ice.front().second;
        ice.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];

            if(0 <= y && y < n && 0 <= x && x < m && !visited[y][x] && !area[y][x])
            {
                visited[y][x] = true;
                ocean.push({{y, x}, 0});
            }
        }
    }
    reset_visited();

    int seq = 0;
    while(1)
    {
        while(ocean.front().second == seq)
        {
            int curr_y = ocean.front().first.first;
            int curr_x = ocean.front().first.second;
            ocean.pop();
            
            bool flag = false;
            for(int i = 0; i < 4; i++)
            {
                int y = curr_y + dy[i];
                int x = curr_x + dx[i];

                if(0 <= y && y < n && 0 <= x && x < m && area[y][x])
                {
                    area[y][x]--;
                    if(!area[y][x])
                    {
                        ocean.push({{y, x}, seq+1});
                    }
                    else
                    {
                        flag = true;
                    }
                }
            }
            ocean.push({{curr_y, curr_x}, seq+1});
        }

        seq++;
        int ice_count = check_ice();
        if(ice_count > 1)
        {
            year = seq;
            break;
        }
        if(ice_count == 0)
        {
            year = 0;
            break;
        }
    }

    cout << year;
}