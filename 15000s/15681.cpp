#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> before_tree;
vector <vector <int>> tree;
vector <int> tree_size;
vector <bool> visited;

void makeTree(int root)
{
    visited[root] = true;
    for(int i : before_tree[root])
    {
        if(!visited[i])
        {
            tree[root].push_back(i);
            makeTree(i);
        }
    }
}

void countTree(int root)
{
    tree_size[root] = 1;
    for(int i : tree[root])
    {
        countTree(i);
        tree_size[root] += tree_size[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, r, q;
    cin >> n >> r >> q;
    before_tree.resize(n+1);
    tree.resize(n+1);
    tree_size.resize(n+1);
    visited.resize(n+1);

    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        before_tree[a].push_back(b);
        before_tree[b].push_back(a);
    }

    makeTree(r);
    countTree(r);

    for(int i = 0; i < q; i++)
    {
        int node;
        cin >> node;
        cout << tree_size[node] << "\n";
    }
}