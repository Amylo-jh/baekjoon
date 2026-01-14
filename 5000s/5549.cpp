#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> jungle(n + 1, vector<int>(m + 1));
    vector<vector<int>> ocean(n + 1, vector<int>(m + 1));
    vector<vector<int>> ice(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++)
        {
            if (str[j-1] == 'J')
            {
                jungle[i][j]++;
            }
            else if (str[j-1] == 'O')
            {
                ocean[i][j]++;
            }
            else if (str[j-1] == 'I')
            {
                ice[i][j]++;
            }
            jungle[i][j] = jungle[i - 1][j] + jungle[i][j - 1] - jungle[i - 1][j - 1] + jungle[i][j];
            ocean[i][j] = ocean[i - 1][j] + ocean[i][j - 1] - ocean[i - 1][j - 1] + ocean[i][j];
            ice[i][j] = ice[i - 1][j] + ice[i][j - 1] - ice[i - 1][j - 1] + ice[i][j];
        }
    }
    while (q--)
    {
        int a, b, c, d, j = 0, o = 0, i = 0;
        cin >> a >> b >> c >> d;
        j = jungle[c][d] - jungle[c][b - 1] - jungle[a - 1][d] + jungle[a - 1][b - 1];
        o = ocean[c][d] - ocean[c][b - 1] - ocean[a - 1][d] + ocean[a - 1][b - 1];
        i = ice[c][d] - ice[c][b - 1] - ice[a - 1][d] + ice[a - 1][b - 1];
        cout << j << " " << o << " " << i << "\n";
    }
}