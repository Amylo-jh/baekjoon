#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, r;
    cin >> n >> m >> r;

    vector <int> items(n);
    vector <bool> visited(n);
    vector <vector <int>> dist(n);

    for(int i = 0; i < n; i++)
    {
        cin >> items[i];
    }
    for(int i = 0; i < n; i++)
    {
        dist[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            dist[i][j] = 1500000;
            if(i == j)
            {
                dist[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int max_item = 0;
    for(int i = 0; i < n; i++)
    {
        int curr_item = 0;
        for(int j = 0; j < n; j++)
        {
            if(dist[i][j] <= m)
            {
                curr_item += items[j];
            }
        }
        max_item = max(max_item, curr_item);
    }

    cout << max_item;
}