#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <vector <vector <bool>>> arr;

int comp(int a, int b)
{
    int count = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(arr[a][i][j] != arr[b][i][j])
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int n;
    cin >> n;
    arr.resize(n);

    for(int i = 0; i < n; i++)
    {
        vector <vector <bool>> tmp(5, vector <bool>(7, false));
        for(int j = 0; j < 5; j++)
        {
            string str;
            cin >> str;
            for(int k = 0; k < 7; k++)
            {
                if(str[k] == 'X')
                {
                    tmp[j][k] = true;
                }
            }
        }
        arr[i] = tmp;
    }

    int min_diff = INT32_MAX;
    pair <int, int> min_target;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int curr_diff = comp(i, j);
            if(curr_diff < min_diff)
            {
                min_diff = curr_diff;
                min_target = {i+1, j+1};
            }
        }
    }

    cout << min_target.first << " " << min_target.second;
}