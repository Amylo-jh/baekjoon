#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector <vector <int>> graph(n+1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int temp;
            cin >> temp;
            if(temp)
            {
                graph[i].push_back(j);
            }
        }
    }

    vector <int> path(m);
    queue <int> bfs_queue;
    vector <bool> visited(n+1);
    for(int i = 0; i < m; i++)
    {
        cin >> path[i];
    }
    bfs_queue.push(path[0]);
    visited[path[0]] = true;
    
    while(!bfs_queue.empty())
    {
        int curr_city = bfs_queue.front();
        bfs_queue.pop();

        for(int i : graph[curr_city])
        {
            if(!visited[i])
            {
                bfs_queue.push(i);
                visited[i] = true;
            }
        }
    }

    bool flag = true;
    for(int i = 0; i < m; i++)
    {
        if(!visited[path[i]])
        {
            flag = false;
            break;
        }
    }

    if(flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}