#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//max_weight, (start, dest);
vector <pair <int, pair<int, int> > > edge;
vector <int> parent;

bool comp(pair <int, pair<int, int>> a, pair <int, pair<int, int>> b)
{
    return a.first > b.first;
}

int find(int node)
{
    if(parent[node] != node)
    {
        parent[node] = find(parent[node]);
    }
    return parent[node];
}

bool make_union(int node1, int node2)
{
    int root1, root2;
    root1 = find(node1);
    root2 = find(node2);

    if(root1 == root2)
    {
        return true;
    }
    else
    {
        parent[root1] = root2;
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, s, e;
    cin >> n >> m >> s >> e;

    edge.resize(m);
    parent.resize(n+1);

    for(int i = 0; i < m; i++)
    {
        int a, b, k;
        cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
    }
    sort(edge.begin(), edge.end(), comp);

    
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int max_weight = 987654321;
    for(int i = 0; i < m; i++)
    {
        int k = edge[i].first;
        int a = edge[i].second.first;
        int b = edge[i].second.second;

        make_union(a, b);
        if(find(s) == find(e))
        {
            max_weight = k;
            break;
        }
    }

    if(max_weight == 987654321)
    {
        cout << 0;
    }
    else
    {
        cout << max_weight;
    }
}