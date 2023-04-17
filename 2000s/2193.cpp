#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long arr[2] = {0, 1};
    long long arr2[2] = {0, 0};
    for(int i = 1; i < n; i++)
    {
        arr2[0] = arr[0];
        arr2[1] = arr[0];
        arr2[0] += arr[1];

        arr[0] = arr2[0];
        arr[1] = arr2[1];
    }

    cout << arr[0] + arr[1];
}