#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector <vector <bool>> arr(n, vector <bool> (m, false));
    vector <vector <bool>> visited(n, vector <bool> (m, false));
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x - 1][y - 1] = true;
    }

    int max_size = 0;
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] && !visited[i][j])
            {
                int size = 0;
                queue <pair <int, int>> bfs_queue;
                bfs_queue.push({i, j});
                visited[i][j] = true;
                while(!bfs_queue.empty())
                {
                    size++;
                    int y = bfs_queue.front().first;
                    int x = bfs_queue.front().second;
                    bfs_queue.pop();
                    for(int l = 0; l < 4; l++)
                    {
                        int ny = y + dy[l];
                        int nx = x + dx[l];
                        if(ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] && !visited[ny][nx])
                        {
                            bfs_queue.push({ny, nx});
                            visited[ny][nx] = true;
                        }
                    }
                }

                max_size = max(max_size, size);
            }
        }
    }

    cout << max_size << "\n";
}