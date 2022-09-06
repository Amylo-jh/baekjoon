#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector <vector <bool>> apart;
vector <vector <bool>> visited;

int bfs(int init_y, int init_x)
{
    queue <pair <int, int>> bfs_queue;
    bfs_queue.push({init_y, init_x});
    visited[init_y][init_x] = true;

    //up, right, down, left
    int y_search[4] = {-1, 0, 1, 0};
    int x_search[4] = {0, 1, 0, -1};

    int houses = 0;
    while (!bfs_queue.empty())
    {
        int curr_y = bfs_queue.front().first;
        int curr_x = bfs_queue.front().second;
        bfs_queue.pop();
        houses++;

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + y_search[i];
            int x = curr_x + x_search[i];

            if(0 <= y && y < n && 0 <= x && x < n &&
            apart[y][x] && !visited[y][x])
            {
                visited[y][x] = true;
                bfs_queue.push({y, x});
            }
        }
    }
    
    return houses;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        vector <bool> temp_vec;
        vector <bool> temp_vec2;
        string str;
        cin >> str;

        for(int j = 0; j < n; j++)
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
        apart.push_back(temp_vec);
        visited.push_back(temp_vec2);
    }

    int count = 0;
    vector <int> houses;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(apart[i][j] && !visited[i][j])
            {
                count++;
                houses.push_back(bfs(i, j));
            }
        }
    }

    sort(houses.begin(), houses.end());

    cout << count << "\n";
    for(int i : houses)
    {
        cout << i << "\n";
    }
}