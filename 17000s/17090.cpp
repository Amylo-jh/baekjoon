#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector <vector <char>> arr;
vector <vector <int>> visited;
stack <pair <int, int>> dfs_stack;

void dfs(int i, int j)
{
    int dy, dx;
    if(arr[i][j] == 'U')
    {
        dy = -1;
        dx = 0;
    }
    else if(arr[i][j] == 'R')
    {
        dy = 0;
        dx = 1;
    }
    else if(arr[i][j] == 'D')
    {
        dy = 1;
        dx = 0;
    }
    else if(arr[i][j] == 'L')
    {
        dy = 0;
        dx = -1;
    }

    if(visited[i][j] == -2 || visited[i][j] == -1)
    {
        while(!dfs_stack.empty())
        {
            int y = dfs_stack.top().first;
            int x = dfs_stack.top().second;
            dfs_stack.pop();
            visited[y][x] = -2;
        }
        return;
    }
    if(visited[i][j] == 1)
    {
        while(!dfs_stack.empty())
        {
            int y = dfs_stack.top().first;
            int x = dfs_stack.top().second;
            dfs_stack.pop();
            visited[y][x] = 1;
        }
        return;
    }

    visited[i][j] = -1;
    dfs_stack.push({i, j});
    if(i + dy < 0 || i + dy >= n || j + dx < 0 || j + dx >= m)
    {
        while(!dfs_stack.empty())
        {
            int y = dfs_stack.top().first;
            int x = dfs_stack.top().second;
            dfs_stack.pop();
            visited[y][x] = 1;
        }
        return;
    }
    else
    {
        dfs(i+dy, j+dx);
    }
}

int main()
{
    cin >> n >> m;
    arr.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        visited[i].resize(m);
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = str[j];
        }
    }

    int counter = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j])
            {
                dfs(i, j);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(visited[i][j] == 1)
            {
                counter++;
            }
        }
    }
    cout << counter;
}
