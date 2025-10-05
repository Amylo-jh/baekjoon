#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector <vector <bool>> arr(n, vector <bool>(m, false));
    vector <vector <int>> dist(n, vector <int>(m, INT32_MAX));
    queue <pair <int, int>> bfs_queue;
    pair <int, int> end;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;
            if(tmp == 3)
            {
                bfs_queue.push({i, j});
                dist[i][j] = 0;
            }
            else if(tmp == 4)
            {
                arr[i][j] = true;
                end = {i, j};
            }
            else if(tmp == 1)
            {
                arr[i][j] = true;
            }
        }
    }

    int dy[8] = {x, x, -x, -x, y, y, -y, -y};
    int dx[8] = {y, -y, y, -y, x, -x, x, -x};
    while(!bfs_queue.empty())
    {
        int cy = bfs_queue.front().first;
        int cx = bfs_queue.front().second;
        int step = dist[cy][cx];
        bfs_queue.pop();
        if(end == make_pair(cy, cx))
        {
            cout << step;
            break;
        }

        for(int i = 0; i < 8; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m && arr[ny][nx] && dist[ny][nx] > step+1)
            {
                bfs_queue.push({ny, nx});
                dist[ny][nx] = step+1;
            }
        }
    }
}