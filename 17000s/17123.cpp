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

        vector <vector <int>> arr(n+1);
        arr[0].resize(n+2);

        for(int i = 1; i <= n; i++)
        {
            arr[i].resize(n+2);
            int sum = 0;
            for(int j = 1; j <= n; j++)
            {
                int temp;
                cin >> temp;
                arr[i][j] = temp - sum;
                sum += arr[i][j];
            }
        }

        for(int i = 0; i < m; i++)
        {
            int r1, c1, r2, c2, v;
            cin >> r1 >> c1 >> r2 >> c2 >> v;

            for(int j = r1; j <= r2; j++)
            {
                arr[j][c1] += v;
                arr[j][c2 + 1] -= v;
            }
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                arr[i][j] += arr[i][j-1];
            }
        }

        for(int i = 1; i <= n; i++)
        {
            int sum = 0;
            for(int j = 1; j <= n; j++)
            {
                sum += arr[i][j];
            }
            cout << sum << " ";
        }

        cout << "\n";

        for(int j = 1; j <= n; j++)
        {
            int sum = 0;
            for(int i = 1; i <= n; i++)
            {
                sum += arr[i][j];
            }
            cout << sum << " ";
        }
        cout << "\n";
    }
}