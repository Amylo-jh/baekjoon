#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<bool> visited;

bool dfs(int curr_node, int depth)
{
    if (depth == 5)
    {
        return true;
    }
    for (int j : arr[curr_node])
    {
        if (!visited[j])
        {
            visited[j] = true;
            if (dfs(j, depth + 1))
            {
                return true;
            }
            visited[j] = false;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    arr.resize(n);
    visited.resize(n, false);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = true;
        if (dfs(i, 1))
        {
            cout << 1;
            return 0;
        }
        visited[i] = false;
    }
    cout << 0;
}