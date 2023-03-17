#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector <vector <int>> node(n+1);
    vector <int> parent(n+1);
    vector <bool> visited(n+1);
    parent[1] = 1;

    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    queue <int> bfs_queue;
    bfs_queue.push(1);
    visited[1] = true;

    while(!bfs_queue.empty())
    {
        int curr_node = bfs_queue.front();
        bfs_queue.pop();
        for(int i : node[curr_node])
        {
            if(!visited[i])
            {
                parent[i] = curr_node;
                bfs_queue.push(i);
                visited[i] = true;
            }
        }
    }

    for(int i = 2; i <= n; i++)
    {
        cout << parent[i] << "\n";
    }
}