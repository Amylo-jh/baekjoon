#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector <vector <int>> arr;
vector <vector <int>> arr2;
vector <vector <bool>> visited;

void dfs(int a, int b)
{
    queue <pair <int, int>> dfs_queue;
    dfs_queue.push({a, b});

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    while(!dfs_queue.empty())
    {
        int curr_y = dfs_queue.front().first;
        int curr_x = dfs_queue.front().second;
        dfs_queue.pop();
        visited[curr_y][curr_x] = true;

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];
            if(0 <= y && y < n && 0 <= x && x < n && !visited[y][x] && arr2[y][x])
            {
                visited[y][x] = true;
                dfs_queue.push({y, x});
            }
        }
    }
}

void reset_visited()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
}

int main()
{
    cin >> n;
    arr.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        arr[i].resize(n);
        visited[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int max_area = 0;
    for(int i = 0; i <= 100; i++)
    {
        arr2 = arr;
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(arr2[j][k] <= i)
                {
                    arr2[j][k] = 0;
                }
            }
        }

        int count = 0;
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(arr2[j][k] && !visited[j][k])
                {
                    count++;
                    dfs(j, k);
                }
            }
        }
        max_area = max(max_area, count);
        reset_visited();
    }

    cout << max_area;
}