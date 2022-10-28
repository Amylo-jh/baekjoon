#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n;
vector <vector <bool>> field;
vector <vector <int>> dist;
vector <vector <bool>> visited;

void dijkstra()
{
    dist[0][0] = 0;
    visited[0][0] = true;

    //거리, y, x
    priority_queue <pair <int, pair<int, int>>> pq;
    pq.push({0, {0, 0}});

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    while(!pq.empty())
    {
        int curr_dist = -pq.top().first;
        int curr_y = pq.top().second.first;
        int curr_x = pq.top().second.second;
        pq.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];
            
            if(0 <= y && y < n && 0 <= x && x < n && !visited[y][x])
            {
                if(field[y][x])
                {
                    dist[y][x] = dist[curr_y][curr_x];
                }
                else
                {
                    dist[y][x] = dist[curr_y][curr_x] + 1;
                }
                visited[y][x] = true;
                pq.push({-dist[y][x], {y, x}});
            }
        }
    }
}

int main()
{
    cin >> n;

    field.resize(n);
    dist.resize(n);
    visited.resize(n);

    for(int i = 0; i < n; i++)
    {
        field[i].resize(n);
        dist[i].resize(n);
        visited[i].resize(n);

        string str;
        cin >> str;
        for(int j = 0; j < n; j++)
        {
            if(str[j] == '1')
            {
                field[i][j] = true;
            }
            else
            {
                field[i][j] = false;
            }
            visited[i][j] = false;
            dist[i][j] = INT32_MAX;
        }
    }

    dijkstra();

    cout << dist[n-1][n-1];
}