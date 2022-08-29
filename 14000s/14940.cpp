#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector <vector <int>> field;
vector <vector <bool>> visited;

void bfs(int p, int q)
{
    queue <pair <int, int>> bfs_queue;
    queue <pair <int, int>> bfs_queue_next;
    bfs_queue.push({p, q});
    int index = 0;
    visited[p][q] = true;

    //up, right, down, left
    int y_move[4] = {-1, 0, 1, 0};
    int x_move[4] = {0, 1, 0, -1};

    while (!bfs_queue.empty())
    {
        int y = bfs_queue.front().first;
        int x = bfs_queue.front().second;
        bfs_queue.pop();
        field[y][x] = index;
        for(int i = 0; i < 4; i++)
        {
            int y_search = y + y_move[i];
            int x_search = x + x_move[i];

            if(0 <= y_search && y_search < n &&
            0 <= x_search && x_search < m &&
            visited[y_search][x_search] == false &&
            field[y_search][x_search] != 0)
            {
                visited[y_search][x_search] = true;
                bfs_queue_next.push({y_search, x_search});
            }
        }    

        if(bfs_queue.empty())
        {
            bfs_queue = bfs_queue_next;
            bfs_queue_next = {};
            index++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
    {
        vector <int> temp_vec(m);
        vector <bool> temp_vec2(m);
        for(int j = 0; j < m; j++)
        {
            cin >> temp_vec[j];
            temp_vec2[j] = false;
            if(temp_vec[j] == 1)
            {
                temp_vec[j] = -1;
            }
        }
        field.push_back(temp_vec);
        visited.push_back(temp_vec2);
    }

    bool flag = true;
    for(int i = 0; i < n && flag; i++)
    {
        for(int j = 0; j < m && flag; j++)
        {
            if(field[i][j] == 2)
            {
                bfs(i, j);
                flag = false;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << field[i][j] << " ";
        }
        cout << "\n";
    }
}