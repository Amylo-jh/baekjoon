#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector <long long> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for(int i = 0; i < k; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;

        for(int j = l; j <= r; j++)
        {
            arr[j] += x;
        }
        sort(arr.begin(), arr.end());
    }

    for(long long i : arr)
    {
        cout << i << " ";
    }
}