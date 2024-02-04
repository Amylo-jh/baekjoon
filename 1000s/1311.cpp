#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector <vector <int>> work;
vector <int> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    work.resize(n);
    for(int i = 0; i < n; i++)
    {
        work[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            cin >> work[i][j];
        }
    }

    for(int i = 0; i < pow(2, n); i++)
    {
        dp.push_back(INT32_MAX);
    }
    dp[0] = 0;

    for(int i = 0; i < pow(2, n); i++)
    {
        int count = 0;
        int num = i;
        while(num)
        {
            count += (num & 1);
            num >>= 1;
        }

        for(int j = 0; j < n; j++)
        {
            int val = i & (1 << j);
            if(!val)
            {
                int val2 = i | (1 << j);
                dp[val2] = min(dp[val2], dp[i] + work[count][j]);
            }
        }
    }

    cout << dp[dp.size()-1];
}