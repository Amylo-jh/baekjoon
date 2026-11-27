#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, l = 0, r = 0, max_len = 0;
    cin >> n >> k;
    vector<int> num(100001);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    while (r < n)
    {
        num[arr[r]]++;
        while (num[arr[r]] > k)
        {
            num[arr[l]]--;
            l++;
        }
        r++;
        max_len = max(max_len, r - l);
    }
    cout << max_len;
}