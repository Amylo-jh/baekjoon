#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> graph;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int v, e;
    cin >> v >> e;
    
    graph.resize(v);
    for(int i = 0; i < v; i++)
    {
        graph[i].resize(v);
        for(int j = 0; j < v; j++)
        {
            graph[i][j] = 90000000;
        }
    }

    for(int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a][b] = c;
    }

    for(int k = 0; k < v; k++)
    {
        for(int i = 0; i < v; i++)
        {
            for(int j = 0; j < v; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int min_val = 90000000;
    for(int i = 0; i < v; i++)
    {
        min_val = min(min_val, graph[i][i]);
    }

    if(min_val == 90000000)
    {
        cout << -1;
    }
    else
    {
        cout << min_val;
    }
}