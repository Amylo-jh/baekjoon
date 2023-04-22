#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector <vector <bool>> area;
vector <vector <int>> dist;
vector <vector <bool>> visited;
int n, m;

void bfs()
{
    queue <pair <int, int>> bfs_queue;
    queue <pair <int, int>> bfs_queue2;
    bfs_queue.push({0, 0});
    visited[0][0] = true;

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    int counter = 0;
    while(!bfs_queue.empty())
    {
        int curr_y = bfs_queue.front().first;
        int curr_x = bfs_queue.front().second;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];

            if(0 <= y && y < n && 0 <= x && x < m && !visited[y][x])
            {
                if(area[y][x])
                {
                    bfs_queue2.push({y, x});
                }
                else
                {
                    bfs_queue.push({y, x});
                    dist[y][x] = dist[curr_y][curr_x];
                }
                visited[y][x] = true;
            }
        }

        if(bfs_queue.empty())
        {
            counter++;
            while(!bfs_queue2.empty())
            {
                int curr_y = bfs_queue2.front().first;
                int curr_x = bfs_queue2.front().second;
                bfs_queue2.pop();

                dist[curr_y][curr_x] = counter;

                bfs_queue.push({curr_y, curr_x});
            }
        }
    }
}

int main()
{
    cin >> m >> n;

    area.resize(n);
    dist.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        area[i].resize(m);
        dist[i].resize(m);
        visited[i].resize(m);

        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == '0')
            {
                area[i][j] = false;
            }
            else
            {
                area[i][j] = true;
            }
        }
    }

    bfs();
    cout << dist[n-1][m-1];
}