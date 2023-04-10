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

    vector <vector <long long>> arr1(n+1);
    vector <vector <long long>> arr2(n+1);
    for(int i = 0; i <= n; i++)
    {
        arr1[i].resize(n+1);
        arr2[i].resize(n+1);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr1[i][j];
        }
    }

    for(int i = 0; i < m-1; i++)
    {
        int dumb;
        int i1, i2, j1, j2, k;
        cin >> dumb >> i1 >> j1 >> i2 >> j2 >> k;
        arr2[i1][j1] += k;
        arr2[i1][j2+1] -= k;
        arr2[i2+1][j1] -= k;
        arr2[i2+1][j2+1] += k;
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            arr2[i][j] += arr2[i][j-1];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            arr2[i][j] += arr2[i-1][j];
        }
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            arr2[i][j] += arr1[i][j];
        }
    }

    long long sum = 0;
    int dumb, i1, i2 ,j1, j2;
    cin >> dumb >> i1 >> j1 >> i2 >> j2;
    for(int i = i1; i <= i2; i++)
    {
        for(int j = j1; j <= j2; j++)
        {
            sum += arr2[i][j];
        }
    }

    cout << sum;
}