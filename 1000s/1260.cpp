#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector <vector <int>> graph;
vector <bool> visited;
void dfs(int start)
{
    cout << start << " ";
    visited[start] = true;
    for(int i : graph[start])
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
}

void bfs(int start)
{
    queue <int> bfs_queue;
    bfs_queue.push(start);
    visited[start] = true;

    while(!bfs_queue.empty())
    {
        int next_node = bfs_queue.front();
        cout << next_node << " ";
        bfs_queue.pop();

        for(int i : graph[next_node])
        {
            if(!visited[i])
            {
                visited[i] = true;
                bfs_queue.push(i);
            }
        }
    }
}

void reset_visited()
{
    for(int i = 0; i < visited.size(); i++)
    {
        visited[i] = false;
    }
}

int main()
{
    int n, m, v;
    cin >> n >> m >> v;

    graph.resize(n+1);
    visited.resize(n+1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout << "\n";
    reset_visited();
    bfs(v);
}