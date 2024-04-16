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

    vector <vector <vector <pair <int, int>>>> arr(n+1, vector <vector <pair <int, int>>> (n+1));
    vector <vector <bool>> visited(n+1, vector <bool> (n+1));
    vector <vector <bool>> light(n+1, vector <bool> (n+1));
    vector <pair <int, int>> lightroom;
    queue <pair <int, int>> lightroom_queue;

    for(int i = 0; i < m; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        arr[x][y].push_back({a, b});
    }

    int count = 1;
    queue <pair <int, int>> bfs_queue;
    lightroom.push_back({1, 1});
    bfs_queue.push({1, 1});
    visited[1][1] = true;
    light[1][1] = true;

    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};

    while(!bfs_queue.empty())
    {
        int y = bfs_queue.front().first;
        int x = bfs_queue.front().second;
        bfs_queue.pop();

        for(auto i : arr[y][x])
        {
            int next_y = i.first;
            int next_x = i.second;

            if(!light[next_y][next_x])
            {
                light[next_y][next_x] = true;
                count++;
            }
        }

        for(auto i : lightroom)
        {
            lightroom_queue.push(i);
        }

        while(!lightroom_queue.empty())
        {
            int y = lightroom_queue.front().first;
            int x = lightroom_queue.front().second;
            lightroom_queue.pop();

            for(int j = 0; j < 4; j++)
            {
                int next_y = y + dy[j];
                int next_x = x + dx[j];

                if(0 < next_y && next_y <= n && 0 < next_x && next_x <= n && !visited[next_y][next_x] && light[next_y][next_x])
                {
                    visited[next_y][next_x] = true;
                    lightroom.push_back({next_y, next_x});
                    lightroom_queue.push({next_y, next_x});
                    bfs_queue.push({next_y, next_x});
                }
            }
        }
    }

    cout << count;
}