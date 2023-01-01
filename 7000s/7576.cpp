#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int>> box;
vector <vector <bool>> visited;
int n, m;

int bfs()
{
    queue <pair <int, int>> bfs_queue;
    queue <pair <int, int>> bfs_queue2;
    int day = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j ++)
        {
            if(box[i][j] == 1)
            {
                bfs_queue.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    while(!bfs_queue.empty())
    {
        int curr_y = bfs_queue.front().first;
        int curr_x = bfs_queue.front().second;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];

            if(0 <= y && y < n && 0 <= x && x < m && !visited[y][x] && box[y][x] == 0)
            {
                bfs_queue2.push({y, x});
                visited[y][x] = true;
                box[y][x] = 1;
            }
        }

        if(bfs_queue.empty())
        {
            if(!bfs_queue2.empty())
            {
                bfs_queue = bfs_queue2;
                bfs_queue2 = {};
                day++;
            }
        }
    }

    bool flag = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(box[i][j] == 0)
            {
                flag = false;
                break;
            }
        }
    }

    int return_value = 0;
    if(flag)
    {
        return_value = day;
    }
    else
    {
        return_value = -1;
    }

    return return_value;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    box.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        box[i].resize(m);
        visited[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            cin >> box[i][j];
        }
    }

    int day = bfs();

    cout << day;
}