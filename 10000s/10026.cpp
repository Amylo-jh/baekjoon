#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n;
vector <vector <char>> area;
vector <vector <bool>> visited;

void bfs(int pos_y, int pos_x)
{
    queue <pair <int, int>> bfs_queue;
    bfs_queue.push({pos_y, pos_x});
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    char start_char = area[pos_y][pos_x];

    visited[pos_y][pos_x] = true;

    while(!bfs_queue.empty())
    {
        int curr_y = bfs_queue.front().first;
        int curr_x = bfs_queue.front().second;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];

            if(0 <= y && y < n && 0 <= x && x < n && !visited[y][x] && start_char == area[y][x])
            {
                bfs_queue.push({y, x});
                visited[y][x] = true;
            }
        }
    }
}

int main()
{
    cin >> n;
    area.resize(n);
    visited.resize(n);

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        area[i].resize(n);
        visited[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            area[i][j] = str[j];
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                count++;
                bfs(i, j);
            }
        }
    }
    cout << count << " ";
    count = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            visited[i][j] = false;
            if(area[i][j] == 'G')
            {
                area[i][j] = 'R';
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                count++;
                bfs(i, j);
            }
        }
    }
    cout << count;
}