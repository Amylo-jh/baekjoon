#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<bool>> arr(102, vector<bool>(102));
    int n, x, y;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        for (int i = x; i < x + 10; i++)
        {
            for (int j = y; j < y + 10; j++)
            {
                arr[i][j] = true;
            }
        }
    }
    int count = 0;
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            if (arr[i][j])
            {
                if (!arr[i - 1][j])
                {
                    count++;
                }
                if (!arr[i + 1][j])
                {
                    count++;
                }
                if (!arr[i][j - 1])
                {
                    count++;
                }
                if (!arr[i][j + 1])
                {
                    count++;
                }
            }
        }
    }
    cout << count;
}