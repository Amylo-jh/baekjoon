#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <bool>> area;
vector <vector <bool>> visited;
int n, m;

int bfs(int y_, int x_)
{
    queue <pair <int, int>> bfs_queue;
    bfs_queue.push({y_, x_});
    visited[y_][x_] = true;

    int d_y[4] = {-1, 0, 1, 0};
    int d_x[4] = {0, 1, 0, -1};

    int counter = 1;
    while(!bfs_queue.empty())
    {
        int init_y = bfs_queue.front().first;
        int init_x = bfs_queue.front().second;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = init_y + d_y[i];
            int x = init_x + d_x[i];

            if(0 <= y && y < n && 0 <= x && x < m &&
            area[y][x] && !visited[y][x])
            {
                bfs_queue.push({y, x});
                visited[y][x] = true;
                counter++;
            }
        }
    }

    return counter;
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    area.resize(n);
    visited.resize(n);

    for(int i = 0; i < n; i++)
    {
        area[i].resize(m);
        visited[i].resize(m);
        int temp;
        for(int j = 0; j < m; j++)
        {
            cin >> temp;
            area[i][j] = temp;
        }
    }

    int paint_count = 0;
    int paint_size = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j] && area[i][j])
            {
                paint_count++;
                paint_size = max(paint_size, bfs(i, j));
            }
        }
    }

    cout << paint_count << "\n" << paint_size;
}