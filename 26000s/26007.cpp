#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, x;
    cin >> n >> m >> k >> x;

    vector <int> rating(n+1);
    vector <int> sum(n+2);
    rating[0] = x;
    for(int i = 1; i <= n; i++)
    {
        int diff;
        cin >> diff;

        rating[i] = rating[i-1] + diff;
        if(rating[i] < k)
        {
            sum[i] += 1;
        }
        sum[i] += sum[i-1];
    }
    sum[n+1] = sum[n];

    for(int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r-1] - sum[l-1] << "\n";
    }
}