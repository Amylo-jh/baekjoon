#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, w;
    cin >> n >> w;

    int map[401][401];
    for(int i = 0; i < w; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = -1;
        map[b][a] = 1;
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(map[i][j] == 0)
                {
                    if(map[i][k] == map[k][j])
                    {
                        map[i][j] = map[i][k];
                        map[j][i] = -map[i][j];
                    }
                }
            }
        }
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        int answer;
        answer = map[a][b] & -map[b][a];
        cout << answer << "\n";
    }   
}