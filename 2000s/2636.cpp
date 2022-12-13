#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int>> area;
vector <vector <bool>> visited;
int n, m;

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

int bfs()
{
    queue <pair <int, int>> bfs_queue;
    bfs_queue.push({0,0});
    visited[0][0] = true;

    int d_y[4] = {-1, 0, 1, 0};
    int d_x[4] = {0, 1, 0, -1};

    while(!bfs_queue.empty())
    {
        int y_ = bfs_queue.front().first;
        int x_ = bfs_queue.front().second;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = y_ + d_y[i];
            int x = x_ + d_x[i];

            if(0 <= y && y < n && 0 <= x && x < m && !visited[y][x])
            {
                visited[y][x] = true;
                if(area[y][x] == 0)
                {
                    bfs_queue.push({y, x});
                }
                else
                {
                    area[y][x] = 2;
                }
            }
        }
    }

    int cheese = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(area[i][j] == 2)
            {
                area[i][j] = 0;
            }
            else if(area[i][j] == 1)
            {
                cheese++;
            }
        }
    }

    return cheese;
}

int main()
{
    cin >> n >> m;
    area.resize(n);
    visited.resize(n);

    int prev_cheese = 0;
    for(int i = 0; i < n; i++)
    {
        area[i].resize(m);
        visited[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            cin >> area[i][j];
            if(area[i][j])
            {
                prev_cheese++;
            }
        }
    }

    int hour = 0;
    int curr_cheese = 0;
    while(prev_cheese)
    {
        reset_visited();
        curr_cheese = bfs();
        hour++;

        if(curr_cheese == 0)
        {
            break;
        }
        else
        {
            prev_cheese = curr_cheese;
        }
    }

    cout << hour << "\n" << prev_cheese;
}