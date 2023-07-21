#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <bool> visited(n+1);
    vector <vector<pair <int, int>>> node(n+1);

    for(int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        node[a].push_back({b, c});
        node[b].push_back({a, c});
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n+1; j++)
        {
            visited[j] = false;
        }
        int a, b;
        cin >> a >> b;

        queue <pair <int, int>> bfs_queue;
        bfs_queue.push({a, 0});
        visited[a] = true;

        while(!bfs_queue.empty())
        {
            int curr_node = bfs_queue.front().first;
            int curr_cost = bfs_queue.front().second;
            bfs_queue.pop();

            if(curr_node == b)
            {
                cout << curr_cost << "\n";
                break;
            }

            for(int j = 0; j < node[curr_node].size(); j++)
            {
                if(!visited[node[curr_node][j].first])
                {
                    bfs_queue.push({node[curr_node][j].first, curr_cost + node[curr_node][j].second});
                    visited[node[curr_node][j].first] = true;
                }
            }
        }
    }
}