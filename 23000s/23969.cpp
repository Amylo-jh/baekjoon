#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k, count = 0;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = n-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                count++;
                swap(arr[j], arr[j + 1]);
                if (count == k)
                {
                    i = -1;
                    break;
                }
            }
        }
    }

    if (count < k)
    {
        cout << -1;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
}