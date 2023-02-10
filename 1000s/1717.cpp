#include <iostream>
#include <vector>

using namespace std;

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
        parent[root_a] = root_b;
        return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    parent.resize(n+1);
    for(int i = 1; i < n+1; i++)
    {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;

        if(op == 0)
        {
            make_union(a, b);
        }
        else
        {
            if(find(a) == find(b))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}