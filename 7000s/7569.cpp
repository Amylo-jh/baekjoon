#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector <vector <vector <int>>> box;
vector <vector <vector <bool>>> visited;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    queue <tuple <int, int, int, int>> bfs_queue;
    int n, m, h;
    cin >> m >> n >> h;
    
    
    box.resize(h);
    visited.resize(h);
    for(int i = 0; i < h; i++)
    {
        box[i].resize(n);
        visited[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            box[i][j].resize(m);
            visited[i][j].resize(m);
            for(int k = 0; k < m; k++)
            {
                cin >> box[i][j][k];
                if(box[i][j][k] == 1)
                {
                    bfs_queue.push(make_tuple(i, j, k, 0));
                    visited[i][j][k] = true;
                }
            }
        }
    }

    vector <vector <int>> d = {{0, 0, 1}, {0, 0, -1}, {0, -1, 0}, {0, 1, 0}, {1, 0, 0}, {-1, 0, 0}};

    int max_day = 0;
    while(!bfs_queue.empty())
    {
        int curr_z = get<0>(bfs_queue.front());
        int curr_y = get<1>(bfs_queue.front());
        int curr_x = get<2>(bfs_queue.front());
        int day = get<3>(bfs_queue.front());
        max_day = max(max_day, day);
        bfs_queue.pop();

        for(int i = 0; i < 6; i++)
        {
            int z = curr_z + d[i][0];
            int y = curr_y + d[i][1];
            int x = curr_x + d[i][2];

            if(0 <= z && z < h && 0 <= y && y < n && 0 <= x && x < m)
            {
                if(!visited[z][y][x] && box[z][y][x] == 0)
                {
                    bfs_queue.push(make_tuple(z, y, x, day+1));
                    visited[z][y][x] = true;
                    box[z][y][x] = 1;
                }
            }
        }
    }

    bool flag = true;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                if(box[i][j][k] == 0)
                {
                    flag = false;
                    i = h;
                    j = n;
                    k = m;
                }
            }
        }
    }

    if(flag)
    {
        cout << max_day;
    }
    else
    {
        cout << -1;
    }

}