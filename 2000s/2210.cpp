#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

vector<vector<int>> arr;
set<stack<int>> st;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int depth, stack<int> stat)
{
    if (depth == 6)
    {
        st.insert(stat);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny && ny < 5 && 0 <= nx && nx < 5)
        {
            stat.push(arr[ny][nx]);
            dfs(ny, nx, depth + 1, stat);
            stat.pop();
        }
    }
}

int main()
{
    arr.resize(5);
    for (int i = 0; i < 5; i++)
    {
        arr[i].resize(5);
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            stack<int> tmp;
            tmp.push(arr[i][j]);
            dfs(i, j, 1, tmp);
            tmp.pop();
        }
    }
    cout << st.size();
}