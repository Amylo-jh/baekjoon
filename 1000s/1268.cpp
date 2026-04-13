#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(6));
    vector<vector<bool>> know(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i == k)
                {
                    continue;
                }
                if (arr[i][j] == arr[k][j])
                {
                    know[i][k] = true;
                }
            }
        }
    }
    int max_meet = 0;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (know[i][j])
            {
                count++;
            }
        }
        if (max_meet < count)
        {
            max_meet = count;
            idx = i;
        }
    }
    cout << idx + 1;
}