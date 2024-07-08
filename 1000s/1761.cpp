#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <vector <pair <int, int>>> adj;
vector <vector <pair <int, int>>> parent;
vector <int> depth;
int n, m, max_depth;

void set_tree(int node, int pnode, int curr_depth)
{
    depth[node] = curr_depth;
    parent[node][0] = {pnode, 0};

    for(int i = 1; i <= max_depth; i++)
    {
        int parent_node = parent[parent[node][i-1]][i-1].first;
        parent[node][i] = {}

    }
}


int main()
{
    cin >> n;
    max_depth = int(floor(log2(n)))+1;
    adj.resize(n+1);
    depth.resize(n+1);
    parent.resize(n+1, vector <pair <int, int>> (max_depth));
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    set_tree(1, 0, 1);
}