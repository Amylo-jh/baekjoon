#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector <vector <int>> area;
vector <vector <bool>> visited;

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

int main()
{
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
        }
    }

    int counter = 0;
    bool flag = true;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    while(flag)
    {
        flag = false;

        queue <pair <int, int>> bfs_queue;
        bfs_queue.push({0, 0});
        visited[0][0] = true;

        while(!bfs_queue.empty())
        {
            int curr_y = bfs_queue.front().first;
            int curr_x = bfs_queue.front().second;
            bfs_queue.pop();

            for(int i = 0; i < 4; i++)
            {
                int y = curr_y + dy[i];
                int x = curr_x + dx[i];

                if(0 <= y && y < n && 0 <= x && x < m && 
                    !visited[y][x])
                {
                    if(area[y][x])
                    {
                        flag = true;
                        area[y][x]++;
                    }   
                    else
                    {
                        visited[y][x] = true;
                        bfs_queue.push({y, x});
                    }
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(area[i][j] > 2)
                {
                    area[i][j] = 0;
                }
                if(area[i][j])
                {
                    area[i][j] = 1;
                }
            }
        }

        if(flag)
        {
            counter++;
        }

        reset_visited();
    }

    cout << counter;
}