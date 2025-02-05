#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <vector <bool>> arr(n, vector <bool> (m, false));
    vector <vector <bool>> visited(n, vector <bool> (m, false));
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == 'L')
            {
                arr[i][j] = true;
            }
        }
    }

    int max_count = 0;
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] && !visited[i][j])
            {
                queue <pair <int, pair <int, int>>> bfs_queue;
                bfs_queue.push({0, {i, j}});
                visited[i][j] = true;

                while(!bfs_queue.empty())
                {
                    int dist = bfs_queue.front().first;
                    int y = bfs_queue.front().second.first;
                    int x = bfs_queue.front().second.second;
                    bfs_queue.pop();

                    for(int k = 0; k < 4; k++)
                    {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if(0 <= ny && ny < n && 0 <= nx && nx < m && arr[ny][nx] && !visited[ny][nx])
                        {
                            visited[ny][nx] = 1;
                            bfs_queue.push({dist + 1, {ny, nx}});
                            max_count = max(max_count, dist + 1);
                        }
                    }
                }

                for(int k = 0; k < n; k++)
                {
                    for(int l = 0; l < m; l++)
                    {
                        visited[k][l] = false;
                    }
                }
            }
        }
    }

    cout << max_count;
}