#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector <vector <bool>> ground;
vector <vector <bool>> visited;
int n, m;

void bfs(int init_y, int init_x)
{
    queue <pair <int, int>> bfs_queue;
    bfs_queue.push({init_y, init_x});
    visited[init_y][init_x] = true;

    //up, right, down, left
    int y_search[4] = {-1, 0, 1, 0};
    int x_search[4] = {0, 1, 0, -1};
    
    while(!bfs_queue.empty())
    {
        int y_start = bfs_queue.front().first;
        int x_start = bfs_queue.front().second;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = y_start + y_search[i];
            int x = x_start + x_search[i];

            if(0 <= y && y < n && 0 <= x && x < m && 
            ground[y][x] && !visited[y][x])
            {
                visited[y][x] = true;
                bfs_queue.push({y, x});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        ground.clear();
        visited.clear();

        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            string temp_str;
            cin >> temp_str;

            vector <bool> temp_vec(m);
            vector <bool> temp_vec2(m);
            for(int j = 0; j < m; j++)
            {
                if(temp_str[j] == '#')
                {
                    temp_vec[j] = true;
                }
                else
                {
                    temp_vec[j] = false;
                }
                temp_vec2.push_back(false);
            }
            ground.push_back(temp_vec);
            visited.push_back(temp_vec2);
        }

        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(ground[i][j] && !visited[i][j])
                {
                    bfs(i, j);
                    count++;
                }
            }
        }

        cout << count << "\n";
    }
}