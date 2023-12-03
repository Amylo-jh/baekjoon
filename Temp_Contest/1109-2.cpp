#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector <vector <bool>> arr(n);
    for(int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == '1')
            arr[i][j] = true;
        }
    }

    int counter = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m-k+1; j++)
        {
            bool flag = true;
            for(int l = 0; l < k; l++)
            {
                if(arr[i][j+l])
                {
                    flag = false;
                }
            }
            if(flag)
            {
                counter++;
            }
        }
    }

    cout << counter;
}