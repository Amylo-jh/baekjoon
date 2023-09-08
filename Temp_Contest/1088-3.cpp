#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector <long long> charactor(n+1);
    vector <pair <long long, int>> boss(k+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> charactor[i];
    }
    for(int i = 1; i <= k; i++)
    {
        cin >> boss[i].first >> boss[i].second;
    }
    sort(charactor.begin(), charactor.end(), greater<>());

    vector <int> meso(m);
    int total_meso = 0;
    for(int curr_char = 0; curr_char < m; curr_char++)
    {
        // 남은 시간, 얻은 메소
        vector <vector <pair <int, long long>>> dp(k+1);
        for(int j = 0; j <= k; j++)
        {
            dp[j].resize(901);
        }

        for(int curr_boss = 1; curr_boss <= k; curr_boss++)
        {
            for(int time = 0; time <= 900; time++)
            {
                long long curr_damage = time* charactor[curr_char];
                long long boss_health = max(boss[curr_boss].first, time* charactor[curr_char]);
                if(curr_damage >= boss_health && curr_damage >= dp[curr_boss][time].second)
                {
                    dp[curr_boss][time].first = max(dp[curr_boss-1][time].first, dp[curr_boss-1][time-(boss[curr_boss].first/charactor[curr_char])].first + boss[curr_boss].second);
                    dp[curr_boss][time].second = curr_damage;
                }
                else
                {
                    dp[curr_boss][time] = dp[curr_boss-1][time];
                }
            }
            cout << "dp[" << curr_boss << "][1500] = " << dp[curr_boss][900] << "\n";
        }

        total_meso += dp[k][900];
    }

    cout << total_meso;

}