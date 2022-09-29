#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int>> prev_image;
vector <vector <int>> next_image;
vector <vector <bool>> visited;
int n, m;

void bfs(int y_init, int x_init)
{
    queue <pair <int, int>> bfs_queue;
    bfs_queue.push({y_init, x_init});
    visited[y_init][x_init] = true;

    //up, right, down, left
    int y_search[4] = {-1, 0, 1, 0};
    int x_search[4] = {0, 1, 0, -1};

    int diff_prev = prev_image[y_init][x_init];
    int diff_next = next_image[y_init][x_init];

    prev_image[y_init][x_init] = diff_next;
    while (!bfs_queue.empty())
    {
        int y_start = bfs_queue.front().first;
        int x_start = bfs_queue.front().second;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = y_start + y_search[i];
            int x = x_start + x_search[i];

            if(0 <= y && y < n && 0 <= x && x < m &&
            !visited[y][x] && prev_image[y][x] == diff_prev)
            {
                prev_image[y][x] = diff_next;
                bfs_queue.push({y, x});
                visited[y][x] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    prev_image.resize(n);
    next_image.resize(n);
    visited.resize(n);

    for(int i = 0; i < n; i++)
    {
        vector <int> temp_vec(m);
        vector <bool> temp_vec2(m);
        for(int j = 0; j < m; j++)
        {
            cin >> temp_vec[j];
            temp_vec2[j] = false;
        }
        prev_image[i] = temp_vec;
        visited[i] = temp_vec2;
    }
    
    for(int i = 0; i < n; i++)
    {
        vector <int> temp_vec(m);
        for(int j = 0; j < m; j++)
        {
            cin >> temp_vec[j];
        }
        next_image[i] = temp_vec;
    }

    int count = 0;
    bool flag = false;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(prev_image[i][j] != next_image[i][j])
            {
                bfs(i, j);
                count++;
                i = 0;
                j = 0;
                
                if(count > 1)
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
        {
            break;
        }
    }

    if(count > 1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
}