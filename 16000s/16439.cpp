#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int>> arr(n, vector <int> (m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int sum = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = i+1; j < m; j++)
        {
            for(int k = j+1; k < m; k++)
            {
                int temp = 0;
                for(int l = 0; l < n; l++)
                {
                    temp += max(arr[l][i], max(arr[l][j], arr[l][k]));
                }
                sum = max(sum, temp);
            }
        }
    }

    cout << sum;
}   