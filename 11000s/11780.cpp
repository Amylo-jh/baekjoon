#include <iostream>
#include <vector>

using namespace std;

int n;
int max_value = 1e9;
int graph [110][110];
int route [110][110];
vector <int> result;

void find_route(int start, int end)
{
    if(route[start][end] == 0)
    {
        result.push_back(start);
        result.push_back(end);
        return;
    }

    find_route(start, route[start][end]);
    result.pop_back();
    find_route(route[start][end], end);
}

void input()
{
    int m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            graph[i][j] = max_value;
        }
    }
    for(int i = 0; i <= n; i++)
    {
        graph[i][i] = 0;
    }
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }
}

void floyd()
{
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    route[i][j] = k;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    floyd();

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(graph[i][j] == max_value)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << graph[i][j] << " ";
            }
        }
        cout << "\n";
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(graph[i][j] == 0 || graph[i][j] == max_value)
            {
                cout << 0;
            }
            else
            {
                result.clear();
                find_route(i, j);
                cout << result.size() << " ";
                for(int k = 0; k < result.size(); k++)
                {
                    cout << result[k] << " ";
                }
            }
            cout << "\n";
        }
    }
}