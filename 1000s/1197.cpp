#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//weight, start, dest;
vector <pair <int, pair<int, int> > > graph;
vector <int> parent;

int find(int node)
{
    if(parent[node] == node)
    {
        return node;
    }
    
    parent[node] = find(parent[node]);
    return parent[node];
}

bool make_union(int a, int b)
{
    if(find(a) != find(b))
    {
        int root_a = find(a);
        int root_b = find(b);

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

    int v, e;
    cin >> v >> e;

    graph.resize(e);
    parent.resize(v);
    for(int i = 0; i < v; i++)
    {
        parent[i] = i;
    }
    
    for(int i = 0; i < e; i++)
    {
        cin >> graph[i].second.first >> graph[i].second.second >> graph[i].first;
        graph[i].second.first--;
        graph[i].second.second--;
    }

    sort(graph.begin(), graph.end());

    long long max_weight = 0;
    for(int i = 0; i < e; i++)
    {
        int a, b, w;
        a = graph[i].second.first;
        b = graph[i].second.second;
        w = graph[i].first;

        bool result = make_union(a, b);
        if(result)
        {
            max_weight += w;
        }
    }

    cout << max_weight;
}