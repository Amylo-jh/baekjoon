#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;

    vector <vector <bool>> arr(m);
    for(int i = 0; i < m; i++)
    {
        arr[i].resize(n);
    }
    for(int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = y1; j < y2; j++)
        {
            for(int k = x1; k < x2; k++)
            {
                arr[j][k] = true;
            }
        }
    }

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    vector <int> result;
    queue <pair <int, int>> bfs_queue;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == false)
            {
                int count = 1;
                bfs_queue.push({i, j});
                arr[i][j] = true;
                while(!bfs_queue.empty())
                {
                    int y = bfs_queue.front().first;
                    int x = bfs_queue.front().second;
                    bfs_queue.pop();

                    for(int i = 0; i < 4; i++)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        if(ny >= 0 && ny < m && nx >= 0 && nx < n && arr[ny][nx] == false)
                        {
                            count++;
                            arr[ny][nx] = true;
                            bfs_queue.push({ny, nx});
                        }
                    }
                }
                result.push_back(count);
            }
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}