#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n, m;
pair <int, int> start;
pair <int, int> dest;

vector <vector <int>> area;
vector <vector <bool>> visited;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void water_init(queue <pair <int, pair <int, int>>> water_queue)
{
    queue <pair <int, pair <int, int>>> bfs_queue;
    while(!water_queue.empty())
    {
        int y = water_queue.front().second.first;
        int x = water_queue.front().second.second;
        bfs_queue.push({0, {y, x}});
        water_queue.pop();
        visited[y][x] = true;
        area[y][x] = -1;
    }

    while(!bfs_queue.empty())
    {
        int seq = bfs_queue.front().first;
        int curr_y = bfs_queue.front().second.first;
        int curr_x = bfs_queue.front().second.second;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];

            if(0 <= y && y < n && 0 <= x && x < m && area[y][x] != -1)
            {
                if(visited[y][x] && area[y][x] > seq+1)
                {
                    bfs_queue.push({seq+1, {y, x}});
                    area[y][x] = seq+1;
                }
                else if(!visited[y][x])
                {
                    bfs_queue.push({seq+1, {y, x}});
                    area[y][x] = seq + 1;
                    visited[y][x] = true;
                }
            }
        }
    }
}

void clear_visited()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
}

int bfs()
{
    queue <pair <int, pair <int, int>>> bfs_queue;
    bfs_queue.push({0, start});
    visited[start.first][start.second] = true;

    int result = -1;

    while(!bfs_queue.empty())
    {
        int seq = bfs_queue.front().first;
        int curr_y = bfs_queue.front().second.first;
        int curr_x = bfs_queue.front().second.second;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];

            if(0 <= y && y < n && 0 <= x && x < m && !visited[y][x])
            {
                if(seq + 1 < area[y][x] || !area[y][x])
                {
                    bfs_queue.push({seq+1, {y, x}});
                    visited[y][x] = true;
                }
                else if(area[y][x] == -1 && make_pair(y, x) == dest)
                {
                    result = seq + 1;
                    bfs_queue = {};
                    break;
                }
            }
        }
    }

    return result;
}

int main()
{
    cin >> n >> m;
    
    area.resize(n);
    visited.resize(n);
    queue <pair <int, pair<int, int>> > water_queue;

    for(int i = 0; i < n; i++)
    {
        area[i].resize(m);
        visited[i].resize(m);
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == '.')
            {
                area[i][j] = 0;
            }
            else if(str[j] == 'X')
            {
                area[i][j] = -1;
            }
            else if(str[j] == 'S')
            {
                start.first = i;
                start.second = j;
                area[i][j] = 0;
            }
            else if(str[j] == 'D')
            {
                dest.first = i;
                dest.second = j;
                area[i][j] = -1;
            }
            else if(str[j] == '*')
            {
                water_queue.push({0, {i, j}});
                area[i][j] = 0;
            }
        }
    }

    water_init(water_queue);
    clear_visited();
    int result = bfs();

    if(result == -1)
    {
        cout << "KAKTUS";
    }
    else
    {
        cout << result;
    }
}