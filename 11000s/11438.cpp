#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <vector <int>> adj;
vector <int> depth;
vector <vector <int>> parent;
int n, m, maxdepth;

void set_tree(int node, int pnode, int curr_depth)
{
    depth[node] = curr_depth;
    parent[node][0] = pnode;

    for(int i = 1; i <= maxdepth; i++)
    {
        parent[node][i] = parent[parent[node][i-1]][i-1];
    }
    for(int i = 0; i < adj[node].size(); i++)
    {
        int childnode = adj[node][i];
        if(childnode != pnode)
        {
            set_tree(childnode, node, curr_depth+1);
        }
    }
}

int lca(int a, int b)
{
    if(a == 1 || b == 1)
    {
        return 1;
    }

    if(depth[a] < depth[b])
    {
        swap(a, b);
    }

    if(depth[a] != depth[b])
    {
        for(int i = maxdepth; i >= 0; i--)
        {
            if(depth[parent[a][i]] >= depth[b])
            {
                a = parent[a][i];
            }
        }
    }

    int result = a;
    if(a != b)
    {
        for(int i = maxdepth; i >= 0; i--)
        {
            if(parent[a][i] != parent[b][i])
            {
                a = parent[a][i];
                b = parent[b][i];
            }
            result = parent[a][i];
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    maxdepth = int(floor(log2(n)))+1;

    adj.resize(n+1);
    depth.resize(n+1);
    parent.resize(n+1, vector <int> (maxdepth+1));
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    set_tree(1, 0, 1);

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;   
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}