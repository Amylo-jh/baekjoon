#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    int n, m;
    cin >> n >> m;

    int div = int(10e8 + 7);
    int cases = 0;

    vector <vector<long long>> arr(n, vector<long long>(m, 0));

    for(int i = 0 ; i < n; i++)
    {
        arr[i][0] = 1;
    }
    for(int i = 0; i < m; i++)
    {
        arr[0][i] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] != 0)
            {
                continue;
            }
            else
            {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j] + arr[i][j-1];
            }

            if(arr[i][j] > div)
            {
                arr[i][j] %= div;
            }
        }
    }

    cout << arr[n-1][m-1];
}