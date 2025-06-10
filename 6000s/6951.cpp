#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, w, p;
    cin >> n >> w >> p;
    vector <vector <int>> graph(n+1, vector <int>(n+1, 1e9));
    for(int i = 0; i < w; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }

    for(int i = 0; i < p; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << graph[a][b] << "\n";
    }
}