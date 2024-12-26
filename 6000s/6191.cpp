#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <vector <int>> arr(n, vector <int> (m));
    vector <vector <bool>> visited(n, vector <bool> (m, false));
    vector <vector <pair <int, int>>> path(n, vector <pair <int, int>> (m, make_pair(-1, -1)));
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == '.')
            {
                arr[i][j] = 0;
            }
            else
            {
                arr[i][j] = 1;
            }
        }
    }

    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};

    queue <pair <int, int>> bfs_queue;
    bfs_queue.push({0, 0});
    visited[0][0] = true;

    while(!bfs_queue.empty())
    {
        int y = bfs_queue.front().first;
        int x = bfs_queue.front().second;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] == true || arr[ny][nx] == 1)
            {
                continue;
            }

            visited[ny][nx] = true;
            path[ny][nx] = {y, x};
            bfs_queue.push({ny, nx});
            if(ny == n - 1 && nx == m - 1)
            {
                break;
            }
        }
    }

    vector <pair <int, int>> answer;
    int y = n - 1;
    int x = m - 1;
    answer.push_back({n, m});
    while(!(y == 0 && x == 0))
    {
        int ny = path[y][x].first;
        int nx = path[y][x].second;
        answer.push_back({ny+1, nx+1});
        y = ny;
        x = nx;
    }

    reverse(answer.begin(), answer.end());
    for(auto it : answer)
    {
        cout << it.first << " " << it.second << "\n";
    }
}