#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> arr1(n, vector<bool>(m));
    vector<vector<bool>> arr2(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '1')
            {
                arr1[i][j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '1')
            {
                arr2[i][j] = true;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                count++;
                for (int ii = i; ii < i + 3; ii++)
                {
                    for (int jj = j; jj < j + 3; jj++)
                    {
                        arr2[ii][jj] = !arr2[ii][jj];
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << count;
}