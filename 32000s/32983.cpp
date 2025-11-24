#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, c, sr, sc;
    cin >> n >> m >> c >> sr >> sc;
    sr--, sc--;
    vector <vector <int>> arr(n, vector <int>(m));
    vector <vector <bool>> visited(n, vector <bool>(m));
    vector <int> coin(1000000);
    vector <int> sum(1000000);
    // dist, y, x
    queue <pair <int, pair <int, int>>> bfs_queue;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    bfs_queue.push({0, {sr, sc}});
    visited[sr][sc] = true;
    while(!bfs_queue.empty())
    {
        int curr_dist = bfs_queue.front().first;
        int cy = bfs_queue.front().second.first;
        int cx = bfs_queue.front().second.second;
        bfs_queue.pop();
        coin[curr_dist] += arr[cy][cx];
        for(int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m && !visited[ny][nx] && arr[ny][nx] != -1)
            {
                bfs_queue.push({curr_dist+1, {ny, nx}});
                visited[ny][nx] = true;
            }
        }
    }
    int max_value = coin[0];
    sum[0] = coin[0];
    for(int i = 1; i < 1000000; i++)
    {
        sum[i] = sum[i-1] + coin[i];
        sum[i] -= c;
        max_value = max(max_value, sum[i]);
    }
    cout << max_value;
}