#include <iostream>
#include <vector>

using namespace std;

vector <int> graph;

int find_root(int a)
{
    if(graph[a] != a)
    {
        graph[a] = find_root(graph[a]);
    }
    
    return graph[a];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    graph.resize(n+1);

    for(int i = 1; i <= n; i++)
    {
        graph[i] = i;
    }

    int count;
    for(count = 1; count <= m; count++)
    {
        int a, b;
        cin >> a >> b;

        int a_root = find_root(a);
        int b_root = find_root(b);

        if(a_root == b_root)
        {
            break;
        }
        else
        {
            graph[b_root] = a_root;
        }
    }

    if(count > m)
    {
        cout << 0;
    }
    else
    {
        cout << count;
    }
}