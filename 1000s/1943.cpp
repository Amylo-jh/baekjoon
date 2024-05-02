#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int tc =0; tc < 3; tc++)
    {
        int n;
        int sum = 0;
        cin >> n;
        vector <pair <int, int>> coin(n);
        for(int i = 0; i < n; i++)
        {
            cin >> coin[i].first >> coin[i].second;
            sum += coin[i].first * coin[i].second;
        }
        
        if(sum % 2 == 1)
        {
            cout << 0 << endl;
            continue;
        }

        vector <int> dp(50001, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = sum / 2; j >= coin[i].first; j--)
            {
                if(dp[j - coin[i].first])
                {
                    for(int k = 0; k < coin[i].second && j + k * coin[i].first <= 50000; k++)
                    {
                        dp[j + k * coin[i].first] = 1;
                    }
                }
            }
        }

        cout << dp[sum / 2] << endl;
    }
}