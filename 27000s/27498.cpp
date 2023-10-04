#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

vector <int> parent;

int find_parent(int node)
{
    if(parent[node] == node)
    {
        return node;
    }
    
    return parent[node] = find_parent(parent[node]);
}

void make_union(int n1, int n2)
{
    int p1 = find_parent(n1);
    int p2 = find_parent(n2);

    if(p1 == p2)
    {
        return;
    }
    if(p1 < p2)
    {
        parent[p2] = p1;
    }
    else
    {
        parent[p1] = p2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector <array<int, 3>> edges(n+1);
    vector <bool> visited(n+1);
    parent.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    priority_queue <array <int, 3>> pq;

    long long all_cost = 0;
    long long included = 0;
    
    for(int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        all_cost += c;
        if(d)
        {
            visited[a] = true;
            visited[b] = true;
            make_union(a, b);
            included += c;
        }
        else
        {
            edges.push_back({c, a, b});
        }
    }


    for(auto &[c, a, b] : edges)
    {
        if(find_parent(a) != find_parent(b))
        {
            pq.push({c, a, b});
        }
    }

    while(!pq.empty())
    {
        int cost = pq.top()[0];
        int n1 = pq.top()[1];
        int n2 = pq.top()[2];
        int p1 = find_parent(n1);
        int p2 = find_parent(n2);
        pq.pop();

        if(p1 != p2)
        {
            make_union(n1, n2);
            included += cost;
        }
    }

    cout << all_cost - included;
}