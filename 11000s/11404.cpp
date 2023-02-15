#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    int max_val = 1000000000;
    cin >> n >> m;

    int floyd[n+1][n+1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            floyd[i][j] = max_val;
        }
        floyd[i][i] = 0;
    }

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        floyd[a][b] = min(floyd[a][b], c);
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
            if(floyd[i][j] == max_val)
            {
                cout << "0 ";
            }
            else
            {
                cout << floyd[i][j] << " ";
            }
        }
        cout << "\n";
    }
}