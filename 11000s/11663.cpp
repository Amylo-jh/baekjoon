#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i = 0 ; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << upper_bound(arr.begin(), arr.end(), b) - lower_bound(arr.begin(), arr.end(), a) << '\n';
    }
}