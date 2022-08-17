#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector <vector <bool>> maze;
vector <vector <bool>> visited;
int n, m;

int bfs(int a, int b)
{
    //up, right, down, left
    int x_search[4] = {0, 1, 0, -1};
    int y_search[4] = {-1, 0, 1, 0};

    queue <pair<int, int>> bfs_queue;
    queue <pair<int, int>> next_bfs_queue;
    bfs_queue.push({0,0});
    visited[a][b] = true;

    int distance = 1;

    while (!bfs_queue.empty())
    {
        int x = bfs_queue.front().second;
        int y = bfs_queue.front().first;
        bfs_queue.pop();

        if(x == m-1 && y == n-1)
        {
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            int x_move = x + x_search[i];
            int y_move = y + y_search[i];

            if(0 <= x_move && x_move < m &&
            0 <= y_move && y_move < n &&
            visited[y_move][x_move] == false &&
            maze[y_move][x_move] == true)
            {
                next_bfs_queue.push({y_move, x_move});
                visited[y_move][x_move] = true;
            }
        }

        if(bfs_queue.empty())
        {
            distance++;
            bfs_queue = next_bfs_queue;
            next_bfs_queue = {};
        }
    }

    return distance;    
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        vector <bool> temp_vec;
        vector <bool> temp_vec2;
        string str;
        cin >> str;

        for(int j = 0; j < m; j++)
        {
            if(str[j] == '1')
            {
                temp_vec.push_back(true);
            }
            else
            {
                temp_vec.push_back(false);
            }
            temp_vec2.push_back(false);
        }

        maze.push_back(temp_vec);
        visited.push_back(temp_vec2);
    }

    int distance = bfs(0,0);

    cout << distance;
}