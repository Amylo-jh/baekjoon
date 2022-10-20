#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, m;
// 0 = empty place, 1 = fence, 2 = wolf, 3 = sheep;
vector <vector <int>> field;
vector <vector <bool>> visited;

int bfs(int y_init, int x_init)
{
    visited[y_init][x_init] = true;
    queue <pair <int, int>> bfs_queue;
    bfs_queue.push({y_init, x_init});
    
    int sheep = 0;
    int wolf = 0;
    int result = 0;

    if(field[y_init][x_init] == 2)
    {
        wolf++;
    }
    else if(field[y_init][x_init] == 3)
    {
        sheep++;
    }

    //up, right, down, left;
    int d_y[4] = {-1, 0, 1, 0};
    int d_x[4] = {0, 1, 0, -1};

    while (!bfs_queue.empty())
    {    
        int y_start = bfs_queue.front().first;
        int x_start = bfs_queue.front().second;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = y_start + d_y[i];
            int x = x_start + d_x[i];

            if(0 <= y && y < n && 0 <= x && x < m &&
            !visited[y][x] && field[y][x] != 1)
            {
                visited[y][x] = true;
                bfs_queue.push({y, x});

                if(field[y][x] == 2)
                {
                    wolf++;
                }
                else if(field[y][x] == 3)
                {
                    sheep++;
                }
            }
        }
    }

    if(sheep > wolf)
    {
        result = sheep;
    }
    else
    {
        result -= wolf;
    }

    return result;    
}

int main()
{
    cin >> n >> m;
    field.resize(n);
    visited.resize(n);

    for(int i = 0;  i < n; i++)
    {
        string str;
        cin >> str;
        vector <int> temp_vec(m);
        vector <bool> temp_vec2(m);
        for(int j = 0; j < m; j++)
        {
            if(str[j] == '.')
            {
                temp_vec[j] = 0;
            }
            else if(str[j] == '#')
            {
                temp_vec[j] = 1;
            }
            else if(str[j] == 'v')
            {
                temp_vec[j] = 2;
            }
            else if(str[j] == 'o')
            {
                temp_vec[j] = 3;
            }
            temp_vec2[j] = false;
        }
        field[i] = temp_vec;
        visited[i] = temp_vec2;
    }

    int sheep = 0;
    int wolf = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j] && (field[i][j] == 2 || field[i][j] == 3))
            {
                // + value : sheep, - value : wolf
                int result = bfs(i, j);
                
                if(result < 0)
                {
                    wolf -= result;
                }
                else
                {
                    sheep += result;
                }
            }
        }
    }

    cout << sheep << " " << wolf;
}