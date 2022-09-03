#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector <vector <bool>> banner;
vector <vector <bool>> visited;

void bfs(int init_y, int init_x)
{
    queue <pair <int, int>> bfs_queue;
    bfs_queue.push({init_y, init_x});
    visited[init_y][init_x] = true;

    // up, up/right, right, right/down, down, down/left, left, left/up
    int y_search[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int x_search[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    while(!bfs_queue.empty())
    {
        int curr_y = bfs_queue.front().first;
        int curr_x = bfs_queue.front().second;
        bfs_queue.pop();

        for(int i = 0; i < 8; i++)
        {
            int y = curr_y + y_search[i];
            int x = curr_x + x_search[i];

            if(0 <= y && y < n && 0 <= x && x < m &&
            banner[y][x] && !visited[y][x])
            {
                visited[y][x] = true;
                bfs_queue.push({y, x});
            }
        }
    }
}

int main()
{    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        vector <bool> temp_vec;
        vector <bool> temp_vec2;
        int num;
        for(int j = 0; j < m; j++)
        {
            cin >> num;
            if(num)
            {
                temp_vec.push_back(true);
            }
            else
            {
                temp_vec.push_back(false);
            }
            temp_vec2.push_back(false);
        }
        banner.push_back(temp_vec);
        visited.push_back(temp_vec2);
    }

    int char_count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(banner[i][j] && !visited[i][j])
            {
                bfs(i, j);
                char_count++;
            }
        }
    }

    cout << char_count;
}