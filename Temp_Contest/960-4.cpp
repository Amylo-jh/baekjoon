#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
vector <vector <bool>> area;
vector <vector <bool>> visited;

int bfs(int start_y, int start_x)
{
    int area_size = 1;
    queue <pair <int, int>> bfs_queue;
    bfs_queue.push({start_y, start_x});
    visited[start_y][start_x] = true;

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    while(!bfs_queue.empty())
    {
        int curr_y = bfs_queue.front().first;
        int curr_x = bfs_queue.front().second;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];

            if(0 <= y && y < n && 0 <= x && x < n && !visited[y][x] && !area[y][x])
            {
                visited[y][x] = true;
                bfs_queue.push({y, x});
                area_size++;
            }
        }
    }

    return area_size;
}

int main()
{
    
    cin >> n >> m >> k;

    area.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        area[i].resize(n);
        visited[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            area[i][j] = temp;
        }
    }

    bool farmable = false;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j] && !area[i][j])
            {
                farmable = true;
                int area_size = bfs(i, j);
                m -= area_size / k;
                area_size %= k;
                if(area_size)
                {
                    m--;
                }
            }
        }
    }

    if(farmable && m >= 0)
    {
        cout << "POSSIBLE\n";
        cout << m;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
}