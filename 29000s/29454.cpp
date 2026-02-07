#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == sum - arr[i])
        {
            cout << i + 1;
            break;
        }
    }
}