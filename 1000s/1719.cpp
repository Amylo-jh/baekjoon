#include <iostream>
#include <vector>

using namespace std;

int max_value = 3000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector <vector <pair <int, int>>> graph(n+1);
    vector <vector <int>> floyd(n+1);
    vector <vector <int>> path(n+1);
    for(int i = 1; i <= n; i++)
    {
        path[i].resize(n+1);
        floyd[i].resize(n+1);
        floyd[i].assign(n+1, max_value);
        floyd[i][i] = 0;
    }

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
        floyd[a][b] = c;
        floyd[b][a] = c;
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                continue;
            }
            int max_cost = max_value;
            for(int k = 0; k < graph[i].size(); k++)
            {
                int curr_cost = graph[i][k].first;
                int curr_node = graph[i][k].second;

                if(curr_cost + floyd[curr_node][j] < max_cost)
                {
                    path[i][j] = curr_node;
                    max_cost = curr_cost + floyd[curr_node][j];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                cout << "- ";
                continue;
            }
            cout << path[i][j] << " ";
        }
        cout << "\n";
    }
}