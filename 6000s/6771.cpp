#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, cat;
    cin >> n >> m >> cat;

    vector <vector <int>> arr(n+1, vector <int> (m+1));
    for(int i = 0; i < cat; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = -1;
    }

    arr[1][1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(arr[i][j] == -1)
            {
                continue;
            }

            if(arr[i-1][j] != -1)
            {
                arr[i][j] += arr[i-1][j];
            }
            if(arr[i][j-1] != -1)
            {
                arr[i][j] += arr[i][j-1];
            }
        }
    }

    cout << arr[n][m];
}