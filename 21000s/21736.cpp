#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    pair <int, int> start;
    vector <vector <int>> area;
    vector <vector <bool>> visited;
    area.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        area[i].resize(m);
        visited[i].resize(m);
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == 'O')
            {
                area[i][j] = 0;
            }
            else if(str[j] == 'X')
            {
                area[i][j] = -1;
            }
            else if(str[j] == 'P')
            {
                area[i][j] = 1;
            }
            else
            {
                start = {i, j};
            }
        }
    }

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    int counter = 0;

    queue <pair <int, int>> bfs_queue;
    bfs_queue.push(start);
    while(!bfs_queue.empty())
    {
        int curr_y = bfs_queue.front().first;
        int curr_x = bfs_queue.front().second;
        visited[curr_y][curr_x] = true;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];

            if(0 <= y && y < n && 0 <= x && x < m && !visited[y][x])
            {
                visited[y][x] = true;
                if(area[y][x] >= 0)
                {
                    bfs_queue.push({y, x});
                    if(area[y][x] == 1)
                    {
                        counter++;
                    }
                }
            }
        }
    }

    if(counter == 0)
    {
        cout << "TT";
    }
    else
    {
        cout << counter;
    }
}