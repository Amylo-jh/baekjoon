#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<bool> arr(n + 1, true);
    for (int i = 2; i <= n; i++)
    {
        if (arr[i])
        {
            for (int j = 1; i * j <= n; j++)
            {
                if (arr[i * j])
                {
                    arr[i * j] = false;
                    k--;
                    if (k == 0)
                    {
                        cout << i * j;
                        return 0;
                    }
                }
            }
        }
    }
}