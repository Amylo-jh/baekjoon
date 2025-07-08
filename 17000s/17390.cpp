#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, l, r;
    cin >> n >> m;
    vector <int> arr(n+1);
    vector <int> sum(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + arr[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> l >> r;
        cout << sum[r] - sum[l-1] << "\n";
    }
}