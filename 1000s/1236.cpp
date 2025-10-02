#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    a = n, b = m;
    vector <vector <bool>> arr(n, vector <bool>(m, false));
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == 'X')
            {
                arr[i][j] = true;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        bool flag = false;
        for(int j = 0; j < m; j++)
        {
            flag |= arr[i][j];
        }
        if(flag)
        {
            a--;
        }
    }
    for(int i = 0; i < m; i++)
    {
        bool flag = false;
        for(int j = 0; j < n; j++)
        {
            flag |= arr[j][i];
        }
        if(flag)
        {
            b--;
        }
    }

    cout << max(a, b);
}