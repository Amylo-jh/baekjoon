#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> temp(n);
    vector <int> index(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        temp[x-1] = i;
    }
    for(int i = 0; i < n; i++)
    {
        index[i] = temp[a[i]-1];
    }

    vector <int> dp(1);
    dp[0] = index[0];
    int pos = 0;
    for(int i = 1; i < n; i++)
    {
        if(dp[pos] < index[i])
        {
            dp.push_back(index[i]);
            pos++;
        }
        else
        {
            int loc = lower_bound(dp.begin(), dp.end(), index[i]) - dp.begin();
            dp[loc] = index[i];
        }
    }

    cout << dp.size();
}