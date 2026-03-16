#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int c1 = 1, c2 = 1, tmp = 0;
    tmp = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > tmp)
        {
            c1++;
            tmp = arr[i];
        }
    }
    tmp = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > tmp)
        {
            c2++;
            tmp = arr[i];
        }
    }
    cout << c1 << "\n"
         << c2;
}