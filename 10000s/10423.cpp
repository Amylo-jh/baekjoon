#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>

using namespace std;

int n, m, k;
vector <vector <pair <int, int>>> node;
vector <int> parent;
vector <bool> visited;
vector <int> generator;

int find_parent(int node)
{
    if(parent[node] != node)
    {
        parent[node] = find_parent(parent[node]);
    }

    return parent[node];
}

void makeUnion(int a, int b)
{
    int pa = find_parent(a);
    int pb = find_parent(b);

    if(pa < pb)
    {
        parent[b] = pa;
    }
    else
    {
        parent[a] = pb;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    node.resize(n+1);
    parent.resize(n+1);
    visited.resize(n+1);
    generator.resize(k);
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for(int i = 0; i < k; i++)
    {
        cin >> generator[i];
        parent[generator[i]] = 0;
        visited[generator[i]] = true;
    }
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        node[u].push_back({v, w});
        node[v].push_back({u, w});
    }

    priority_queue <array <int, 3>, vector <array <int, 3>>, greater<>> pq;
    for(int i = 0; i < k; i++)
    {
        for(pair <int, int> p : node[generator[i]])
        {
            pq.push({p.second, generator[i], p.first});
        }
    }

    int total_cost = 0;
    while(!pq.empty())
    {
        array <int, 3> ca = pq.top();
        pq.pop();

        int pa = find_parent(ca[1]);
        int pb = find_parent(ca[2]);
        int cost = ca[0];
        if(pa != pb)
        {
            makeUnion(ca[1], ca[2]);
            total_cost += cost;

            if(!visited[ca[1]])
            {
                for(pair <int, int> p : node[ca[1]])
                {
                    pq.push({p.second, ca[1], p.first});
                }
                visited[ca[1]] = true;
            }
            if(!visited[ca[2]])
            {
                for(pair <int, int> p : node[ca[2]])
                {
                    pq.push({p.second, ca[2], p.first});
                }
                visited[ca[2]] = true;
            }
        }
    }

    cout << total_cost;
}