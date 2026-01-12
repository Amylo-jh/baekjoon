#include <iostream>

using namespace std;

int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    int sum = 0, tmp = 0, bread;
    for (int i = 0; i < n; i++)
    {
        tmp = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> bread;
            if (bread)
            {
                tmp++;
            }
        }
        if (m - tmp < p)
        {
            sum++;
        }
    }
    cout << sum;
}