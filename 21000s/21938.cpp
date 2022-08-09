#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector <vector <int>> screen;
vector <vector <bool>> visited;

void bfs(int i, int j)
{
    queue <pair <int, int>> bfs_queue;
    bfs_queue.push({j, i});
    visited[i][j] = true;
    
    //up, right, down, left
    int search_x[4] = {0, 1, 0, -1};
    int search_y[4] = {-1, 0, 1, 0};

    while(!bfs_queue.empty())
    {
        int x = bfs_queue.front().first;
        int y = bfs_queue.front().second;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            if(0 <= x + search_x[i] && x + search_x[i] < m &&
            0 <= y + search_y[i] && y + search_y[i] < n &&
            visited[y + search_y[i]][x + search_x[i]] == false)
            {
                if(screen[y + search_y[i]][x + search_x[i]] == 1)
                {
                    bfs_queue.push({x + search_x[i], y + search_y[i]});
                    visited[y + search_y[i]][x + search_x[i]] = true;
                }
            }
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
        vector <int> temp_vector;
        vector <bool> temp_visited;
        for(int j = 0; j < m; j++)
        {
            int temp_pixel = 0;
            int input;
            for(int k = 0; k < 3; k++)
            {
                cin >> input;
                temp_pixel += input;
            }
            temp_pixel /= 3;
            temp_vector.push_back(temp_pixel);
            temp_visited.push_back(false);
        }
        screen.push_back(temp_vector);
        visited.push_back(temp_visited);
    }

    int boundary;
    cin >> boundary;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(screen[i][j] >= boundary)
            {
                screen[i][j] = 1;
            }
            else
            {
                screen[i][j] = 0;
            }
        }
    }

    int object_count = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(screen[i][j] == 1 && visited[i][j] == false)
            {
                object_count++;
                bfs(i, j);
            }
        }
    }

    cout << object_count;
}