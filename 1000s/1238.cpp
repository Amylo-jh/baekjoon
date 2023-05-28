#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x;
    cin >> n >> m >> x;
    
    vector <vector <int>> area(n+1);
    for(int i = 0; i < n+1; i++)
    {
        area[i].resize(n+1);
        for(int j = 0; j < n+1; j++)
        {
            area[i][j] = INT32_MAX;
            if(i == j)
            {
                area[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;

        area[start][end] = cost;
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(area[i][k] == INT32_MAX || area[k][j] == INT32_MAX)
                {
                    continue;
                }
                area[i][j] = min(area[i][j], area[i][k] + area[k][j]);
            }
        }
    }

    int max_time = 0;
    for(int i = 1; i <= n; i++)
    {
        max_time = max(max_time, area[i][x] + area[x][i]);
    }

    cout << max_time;
}