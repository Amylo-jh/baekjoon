#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 1;
int m = 1;

vector <vector <bool>> field;
vector <vector <bool>> visited;

void bfs(int i, int j)
{
    queue <pair <int, int>> bfs_queue;
    int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
    visited[i][j] = true;
    bfs_queue.push({i, j});

    while(!bfs_queue.empty())
    {
        int init_y = bfs_queue.front().first;
        int init_x = bfs_queue.front().second;
        bfs_queue.pop();

        for(int k = 0; k < 8; k++)
        {
            int y = init_y + dy[k];
            int x = init_x + dx[k];

            if(0 <= y && y < n && 0 <= x && x < m
            && field[y][x] && !visited[y][x])
            {
                visited[y][x] = true;
                bfs_queue.push({y, x});
            }
        }
    }
}

int main()
{
    while(1)
    {
        cin >> m >> n;
        if(n == 0 && m == 0)
        {
            break;
        }

        field.resize(n);
        visited.resize(n);
        
        for(int i = 0; i < n; i++)
        {
            field[i].resize(m);
            visited[i].resize(m);
            for(int j = 0; j < m; j++)
            {
                int p;
                cin >> p;
                field[i][j] = p;
                visited[i][j] = false;
            }
        }

        int island = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(field[i][j] && !visited[i][j])
                {
                    bfs(i, j);
                    island++;
                }
            }
        }

        cout << island << "\n";
    }    
}