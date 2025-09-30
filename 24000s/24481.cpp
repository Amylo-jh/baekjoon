#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r;
vector <vector <int>> arr;
vector <int> depth;
vector <bool> visited;

void dfs(int c_node, int c_depth)
{
    depth[c_node] = c_depth;
    visited[c_node] = true;
    for(auto i : arr[c_node])
    {
        if(!visited[i])
        {
            dfs(i, c_depth+1);
        }
    }
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> r;
    arr.resize(n+1);
    depth.resize(n+1, -1);
    visited.resize(n+1);
    depth[r] = 0;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        sort(arr[i].begin(), arr[i].end());
    }

    dfs(r, 0);
    for(int i = 1; i <= n; i++)
    {
        cout << depth[i] << "\n";
    }
}