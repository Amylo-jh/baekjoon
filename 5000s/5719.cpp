#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, s, d;
vector <vector <pair <int, int>>> adj;
vector <vector <int>> prev_node;
vector <bool> visited;
int dijkstra()
{
    priority_queue <pair <int, int>> pq;
    vector <int> dist(n, 1e9);
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty())
    {
        int curr_dist = -pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if(curr_dist > dist[curr_node])
        {
            continue;
        }

        for(auto next : adj[curr_node])
        {
            int next_node = next.first;
            int next_dist = next.second;

            if(dist[next_node] == curr_dist + next_dist)
            {
                prev_node[next_node].push_back(curr_node);
            }
            else if(dist[next_node] > curr_dist + next_dist)
            {
                prev_node[next_node].clear();
                prev_node[next_node].push_back(curr_node);
                dist[next_node] = dist[curr_node] + next_dist;
                pq.push({-dist[next_node], next_node});
            }
        }
    }

    return dist[d] == 1e9 ? -1 : dist[d];
}

void remove_path_bfs()
{
    queue <int> bfs_queue;
    bfs_queue.push(d);
    while(!bfs_queue.empty())
    {
        int curr = bfs_queue.front();
        bfs_queue.pop();
        
        if(visited[curr])
        {
            continue;
        }
        visited[curr] = true;
        
        for(int prev : prev_node[curr])
        {
            for(int i = 0; i < adj[prev].size(); i++)
            {
                if(adj[prev][i].first == curr)
                {
                    adj[prev][i].second = 1e9;
                }
            }
            bfs_queue.push(prev);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        cin >> n >> m;
        if(n == 0 && m == 0)
        {
            break;
        }
        cin >> s >> d;

        adj.clear();
        adj.resize(n);
        visited.clear();
        visited.resize(n, false);
        prev_node.clear();
        prev_node.resize(n);
        
        for(int i = 0; i < m; i++)
        {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u].push_back({v, p});
        }

        int min_dist = dijkstra();
        remove_path_bfs();
        int min_dist2 = dijkstra();
        if(min_dist2 == -1)
        {
            cout << -1;
        }
        else
        {
            cout << min_dist2;
        }
        cout << "\n";
    }
}