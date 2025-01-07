#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;

    vector <vector <bool>> arr(n, vector <bool> (m, false));
    vector <vector <bool>> visited(n, vector <bool> (m, false));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            arr[i][j] = bool(temp);
        }
    }

    int dy[2] = {1, 0};
    int dx[2] = {0, 1};
    queue <pair <int, int>> bfs_queue;
    bfs_queue.push(make_pair(0, 0));
    visited[0][0] = true;

    bool flag = false;
    while(!bfs_queue.empty())
    {
        int y = bfs_queue.front().first;
        int x = bfs_queue.front().second;
        bfs_queue.pop();

        if(y == n - 1 && x == m - 1)
        {
            cout << "Yes";
            return 0;
        }

        for(int i = 0; i < 2; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(0 <= ny && ny < n && 0 <= nx && nx < m)
            {
                if(arr[ny][nx] && !visited[ny][nx])
                {
                    bfs_queue.push(make_pair(ny, nx));
                    visited[ny][nx] = true;
                }
            }
        }
    }
    
    cout << "No";
}