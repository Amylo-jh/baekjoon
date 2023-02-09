#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <int, pair <int, int>> > graph;
vector <int> parent;
    
int find(int node)
{
    if(parent[node] != node)
    {
        parent[node] = find(parent[node]);
    }
    return parent[node];
}

bool make_union(int a, int b)
{
    int root_a = find(a);
    int root_b = find(b);

    if(root_a != root_b)
    {
        parent[root_b] = root_a;
        return true;
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

    graph.resize(m);
    parent.resize(n+1);
        
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++)
    {
        cin >> graph[i].second.first >> graph[i].second.second >> graph[i].first;
    }

    sort(graph.begin(), graph.end());

    int total_cost = 0;
    for(int i = 0; i < m; i++)
    {
        int a = graph[i].second.first;
        int b = graph[i].second.second;
        int cost = graph[i].first;

        if(make_union(a, b))
        {
            total_cost += cost;
        }
    }

    cout << total_cost;
}