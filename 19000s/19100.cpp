#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    cin >> n >> t;
    vector<int> arr(1 << n);
    for (int i = 0; i < (1 << n); i++)
    {
        cin >> arr[i];
    }
    if (t % 2)
    {
        reverse(arr.begin(), arr.end());
    }
    for (auto i : arr)
    {
        cout << i << " ";
    }
}