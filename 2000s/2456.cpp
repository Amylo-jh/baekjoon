#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector <vector <int>> arr(n+1);
    vector <vector <int>> dist(n+1, vector <int> (n+1, INT32_MAX/3));
    for(int i = 0; i <= n; i++)
    {
        dist[i][i] = 0;
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= n; j++)
        {
            if(dist[i][j] != INT32_MAX/3 || dist[j][i] != INT32_MAX/3)
            {
                cnt++;
            }
        }
        if(cnt == n)
        {
            answer++;
        }
    }

    cout << answer;   
}