#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector <vector <int>> arr(n, vector <int> (m));
    vector <vector <bool>> visited(n, vector <bool>(m, false));
    priority_queue <pair <int, pair <int, int>>> pq;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            pq.push({arr[i][j], {i, j}});
        }
    }   

    int count = 0;
    int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    while(!pq.empty())
    {
        int height = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();

        if(visited[i][j])
        {
            continue;
        }
        visited[i][j] = true;
        count++;

        // prev_height, prev_yx;
        queue <pair <int , pair <int, int>>> bfs_queue;
        bfs_queue.push({arr[i][j], {i, j}});
        while(!bfs_queue.empty())
        {
            int curr_height = bfs_queue.front().first;
            int curr_y = bfs_queue.front().second.first;
            int curr_x = bfs_queue.front().second.second;
            bfs_queue.pop();

            for(int k = 0; k < 8; k++)
            {
                int y = curr_y + dy[k];
                int x = curr_x + dx[k];
                if(0 <= y && y < n && 0 <= x && x < m && !visited[y][x])
                {
                    if(arr[curr_y][curr_x] - arr[y][x] >= 0)
                    {
                        visited[y][x] = true;
                        bfs_queue.push({arr[y][x], {y, x}});
                    }
                }
            }
        }   
    }
    cout << count;
}