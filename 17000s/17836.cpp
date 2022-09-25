#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, t;
vector <vector <int>> field;
vector <vector <bool>> visited;

int time_to_princess = 100000;
int time_to_knife = 100000;
int distance_to_knife_to_princess = 100000;


void bfs()
{
    queue <pair <int, int>> bfs_queue;
    queue <pair <int, int>> bfs_queue2;
    bfs_queue.push({0,0});
    visited[0][0] = true;

    //up, right, down, left
    int y_search[4] = {-1, 0, 1, 0};
    int x_search[4] = {0, 1, 0, -1};

    int time = 1;
    while(!bfs_queue.empty())
    {
        int curr_y = bfs_queue.front().first;
        int curr_x = bfs_queue.front().second;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + y_search[i];
            int x = curr_x + x_search[i];

            if(0 <= y && y < n && 0 <= x && x < m &&
            field[y][x] != 1 && !visited[y][x])
            {
                if(field[y][x] == 2)
                {
                    time_to_knife = min(time, time_to_knife);
                    distance_to_knife_to_princess = (n - 1 - y) + (m - 1 - x);
                }
                if(y == n-1 && x == m-1)
                {
                    time_to_princess = min(time, time_to_princess);
                }
                visited[y][x] = true;
                bfs_queue2.push({y, x});
            }
        }

        if(bfs_queue.empty())
        {
            bfs_queue = bfs_queue2;
            bfs_queue2 = {};
            time++;
        }
    }
}

int main()
{
    cin >> n >> m >> t;
    field.resize(n);
    visited.resize(n);

    for(int i = 0; i < n; i++)
    {
        field[i].resize(m);
        visited[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            cin >> field[i][j];
            visited[i][j] = false;
        }
    }

    bfs();

    if(t >= min(time_to_princess, time_to_knife + distance_to_knife_to_princess))
    {
        cout << min(time_to_princess, time_to_knife + distance_to_knife_to_princess);
    }
    else
    {
        cout << "Fail";
    }
}