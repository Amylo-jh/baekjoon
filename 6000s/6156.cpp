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
    vector<vector<int>> dist(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] && dist[k][j])
                {
                    dist[i][j] = 1;
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = n - 1;
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] || dist[j][i])
            {
                cnt--;
            }
        }
        if (cnt == 0)
        {
            answer++;
        }
    }
    cout << answer;
}