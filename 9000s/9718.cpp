#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int n, m;
        cin >> n >> m;
        vector <vector <int>> arr(n, vector <int> (m));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m-1; j++)
            {
                arr[i][j+1] -= arr[i][j];
                arr[i][j] = 0;
            }
        }

        for(int i = 0; i < n-1; i++)
        {
            arr[i+1][m-1] -= arr[i][m-1];
            arr[i][m-1] = 0;
        }

        if(arr[n-1][m-1] == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}