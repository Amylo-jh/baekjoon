#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int block1 = 0, block2 = 0;
vector <vector <pair <int, int>>> adj;
vector <int> parent;
bool first = true;

bool unlink(int c1, int c2)
{
    if((block1 == c1 || block1 == c2) && (block2 == c1 || block2 == c2))
    {
        return true;
    }
    return false;
}

int dijkstra()
{
    // cost, node
    priority_queue <pair <int, int>> pq;
    vector <int> dist(n+1, 1e9);
    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(cost > dist[node])
        {
            continue;
        }
        for(int i = 0; i < adj[node].size(); i++)
        {
            int next = adj[node][i].first;
            if(unlink(node, next))
            {
                continue;
            }
            int nextcost = cost + adj[node][i].second;
            if(nextcost < dist[next])
            {
                dist[next] = nextcost;
                pq.push({-nextcost, next});
                if(first)
                {
                    parent[next] = node;
                }
            }
        }
    }

    return dist[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    adj.resize(n + 1);
    parent.resize(n + 1);

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    parent[1] = 1;
    int time = dijkstra();
    int maxtime = time;
    first = false;

    for(int i = n; i != parent[i]; i = parent[i])
    {
        block1 = i;
        block2 = parent[i];
        maxtime = max(maxtime, dijkstra());
        if(maxtime >= 1e9)
        {
            break;
        }
    }

    if(maxtime >= 1e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << maxtime - time << endl;
    }
}