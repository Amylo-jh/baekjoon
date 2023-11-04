#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
int dy[3] = {-1, 0, 1};
vector <vector <bool>> area;
vector <vector <bool>> visited;

bool dfs(int curr_y, int x)
{
    if(x == m-1)
    {
        return true;
    }

    bool result = false;
    area[curr_y][x] = true;
    visited[curr_y][x] = true;
    for(int i = 0; i < 3; i++)
    {
        int y = curr_y + dy[i];
        if(0 <= y && y < n && !area[y][x+1] && !visited[y][x+1])
        {
            result = dfs(y, x+1);
            if(result)
            {
                break;
            }
        }
    }

    visited[curr_y][x] = false;
    if(!result)
    {
        area[curr_y][x] = false;
        visited[curr_y][x] = true;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    area.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        area[i].resize(m);
        visited[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            if(str[j] == 'x')
            {
                area[i][j] = true;
            }
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        bool result = dfs(i, 0);
        if(result)
        {
            count++;
        }
    }

    cout << count;
}