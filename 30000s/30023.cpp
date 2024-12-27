#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;
    
    vector <vector <int>> arr(3, vector <int> (n, 0));
    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'R')
        {
            arr[0][i] = 0;
        }
        else if(str[i] == 'G')
        {
            arr[0][i] = 1;
        }
        else if(str[i] == 'B')
        {
            arr[0][i] = 2;
        }
    }
    arr[1] = arr[2] = arr[0];

    vector <int> count = {0, 1, 2};
    arr[1][0] = (arr[1][0]+1) % 3;
    arr[1][1] = (arr[1][1]+1) % 3;
    arr[1][2] = (arr[1][2]+1) % 3;
    arr[2][0] = (arr[2][0]+2) % 3;
    arr[2][1] = (arr[2][1]+2) % 3;
    arr[2][2] = (arr[2][2]+2) % 3;

    for(int i = 1; i <= n-3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            while(arr[j][i-1] != arr[j][i])
            {
                arr[j][i] = (arr[j][i]+1) % 3;
                arr[j][i+1] = (arr[j][i+1]+1) % 3;
                arr[j][i+2] = (arr[j][i+2]+1) % 3;
                count[j]++;
            }
        }
    }

    int min_count = INT32_MAX;
    for(int i = 0; i < 3; i++)
    {
        bool flag = true;
        for(int j = 0; j < n-1; j++)
        {
            if(arr[i][j] != arr[i][j+1])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            min_count = min(min_count, count[i]);
        }
    }

    if(min_count == INT32_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << min_count;
    }
}