#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int>> field;
int n, m, k;

void bfs(int input_y, int input_x)
{
    queue <pair<int, int>> bfs_queue;
    bfs_queue.push({input_y, input_x});
    field[input_y][input_x] = 1;

    while(!bfs_queue.empty())
    {
        int queue_x = bfs_queue.front().second;
        int queue_y = bfs_queue.front().first;
        bfs_queue.pop();

        //up, right, down, left
        int x[4] = {queue_x, queue_x+1, queue_x, queue_x-1};
        int y[4] = {queue_y-1, queue_y, queue_y+1, queue_y};

        for(int i = 0; i < 4; i++)
        {
            //area validation & check not visited
            if(0 <= x[i] && x[i] < m
            && 0 <= y[i] && y[i] < n
            && field[y[i]][x[i]] == -1)
            {
                bfs_queue.push({y[i], x[i]});
                field[y[i]][x[i]] = 1;
            }
        }
    }
}

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        field.clear();        
        cin >> m >> n >> k;

        for(int i = 0; i < n; i++)
        {
            vector <int> temp_vec;
            for(int j = 0; j < m; j++)
            {
                temp_vec.push_back(0);
            }
            field.push_back(temp_vec);
        }

        for(int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            field[y][x] = -1;
        }

        int bug = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(field[i][j] == -1)
                {
                    bfs(i, j);
                    bug++;
                }
            }
        }

        cout << bug << endl;
    }
}