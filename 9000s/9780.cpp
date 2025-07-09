#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        long long n, q, l, r;
        cin >> n >> q;
        vector <long long> arr(n+1);
        vector <long long> sum(n+1);
        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            sum[i] = sum[i-1] + arr[i];
        }
        while(q--)
        {
            cin >> l >> r;
            l++;
            r++;
            cout << sum[r] - sum[l-1] << "\n";
        }
        cout << "\n";
    }
}