#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

vector <int> parent;

int find_parent(int node)
{
    if(node == parent[node])
    {
        return node;
    }

    return parent[node] = find_parent(parent[node]);
}

void make_union(int n1, int n2)
{
    int p1 = find_parent(n1);
    int p2 = find_parent(n2);
    if(p1 != p2)
    {
        parent[p1] = p2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, maxday = 1;
    cin >> n >> m;

    vector <array <int, 3>> edge(m);
    parent.resize(n+1);
    for(int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
    for(int i = 0; i < m; i++)
    {
        int a, b, t;
        cin >> edge[i][1] >> edge[i][2] >> edge[i][0];
    }
    sort(edge.begin(), edge.end());

    for(int i = 0; i < m; i++)
    {
        int u = edge[i][1];
        int v = edge[i][2];
        int t = edge[i][0];

        if(maxday != t)
        {
            break;
        }
        if(find_parent(u) != find_parent(v))
        {
            make_union(u, v);
            maxday++;
        }
    }

    cout << maxday;
}