#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <vector <int>> arr(n, vector <int> (m, 0));
    vector <vector <bool>> visited(n, vector <bool> (m, 0));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int max_dist = 0;
    int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dx[8] = {1, 0, -1, 1, -1, 1, 0, -1};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int ii = 0; ii < n; ii++)
            {
                for(int jj = 0; jj < m; jj++)
                {
                    visited[ii][jj] = false;
                }
            }

            if(arr[i][j] == 1)
            {
                continue;
            }

            queue <pair <int, int>> bfs_queue;
            bfs_queue.push({i, j});
            visited[i][j] = true;

            while(!bfs_queue.empty())
            {
                int curr_y = bfs_queue.front().first;
                int curr_x = bfs_queue.front().second;
                bfs_queue.pop();

                for(int k = 0; k < 8; k++)
                {
                    int y = curr_y + dy[k];
                    int x = curr_x + dx[k];

                    if(0 <= y && y < n && 0 <= x && x < m && !visited[y][x])
                    {
                        visited[y][x] = true;
                        if(arr[y][x] == 1)
                        {
                            if(max_dist < max(abs(y - i), abs(x - j)))
                            {
                                max_dist = max(abs(y - i), abs(x - j));
                            }
                            
                            bfs_queue = {};
                            break;
                        }
                        bfs_queue.push({y, x});
                    }
                }
            }
        }
    }

    cout << max_dist;
}