#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, cnt = 0;
vector <vector <int>> arr;
vector <vector <int>> visited;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x)
{
    visited[y][x] = 1;
    int ny = y + dy[arr[y][x]];
    int nx = x + dx[arr[y][x]];

    if(visited[ny][nx] == 0)
    {
        dfs(ny, nx);
    }
    else if(visited[ny][nx] == 1)
    {
        cnt++;
    }

    visited[y][x] = 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.resize(n, vector <int>(m, 0));
    visited.resize(n, vector <int>(m, 0));

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == 'U')
            {
                arr[i][j] = 0;
            }
            else if(str[j] == 'R')
            {
                arr[i][j] = 1;
            }
            else if(str[j] == 'D')
            {
                arr[i][j] = 2;
            }
            else if(str[j] == 'L')
            {
                arr[i][j] = 3;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(visited[i][j] == 0)
            {
                dfs(i, j);
            }
        }
    }

    cout << cnt;
}