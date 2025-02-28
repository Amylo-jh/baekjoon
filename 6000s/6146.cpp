#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, n;
    cin >> x >> y >> n;
    // offset : 1000
    x += 1000;
    y += 1000;
    vector <vector <int>> arr(2000, vector <int> (2000, 0));
    vector <vector <bool>> visited(2000, vector <bool> (2000, false));
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> b >> a;
        arr[a + 1000][b + 1000] = -1;
    }

    queue <pair <int, pair <int, int>>> bfs_queue;
    bfs_queue.push({0, {1000, 1000}});
    visited[1000][1000] = true;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    while(!bfs_queue.empty())
    {
        int dist = bfs_queue.front().first;
        int curr_y = bfs_queue.front().second.first;
        int curr_x = bfs_queue.front().second.second;
        bfs_queue.pop();

        if(curr_y == y && curr_x == x)
        {
            cout << dist;
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            int next_y = curr_y + dy[i];
            int next_x = curr_x + dx[i];

            if(0 <= next_y && next_y < 2000 && 0 <= next_x && next_x < 2000 && !visited[next_y][next_x])
            {
                if(arr[next_y][next_x] == 0)
                {
                    bfs_queue.push({dist+1, {next_y, next_x}});
                }
                visited[next_y][next_x] = true;
            }
        }
    }
}