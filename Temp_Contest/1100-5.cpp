#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector <int> blackhole(n);
    vector <pair <int, int>> asteroid(m);
    vector <vector <int>> min_power(n);
    for(int i = 0; i < n; i++)
    {
        cin >> blackhole[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> asteroid[i].first >> asteroid[i].second;
    }
    sort(blackhole.begin(), blackhole.end());
    sort(asteroid.begin(), asteroid.end());

    for(int i = 0; i < m; i++)
    {
        int lower_bh = lower_bound(blackhole.begin(), blackhole.end(), asteroid[i].first) - blackhole.begin();        
        int lower_bh_1 = lower_bh-1;

        if(lower_bh_1 < 0)
        {
            lower_bh_1 = lower_bh;
        }
        if(lower_bh >= n)
        {
            lower_bh = lower_bh_1;
        }
        int lower_bh_pos = blackhole[lower_bh];
        int lower_bh_1_pos = blackhole[lower_bh_1];

        int curr_ast_pos = asteroid[i].first;
        int curr_ast_wei = asteroid[i].second;

        int dist = 0;
        int dist1 = abs(curr_ast_pos - lower_bh_pos);
        int dist2 = abs(curr_ast_pos - lower_bh_1_pos);
        int used_bh = 0;
        if(dist1 <= dist2)
        {
            used_bh = lower_bh;
            dist = dist1;
        }
        else
        {
            used_bh = lower_bh_1;
            dist = dist2;
        }
        
        min_power[used_bh].push_back(dist * curr_ast_wei);
    }

    int min_p = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < min_power[i].size(); j++)
        {
            min_p = max(min_p, min_power[i][j]);
        }
    }

    cout << min_p;
}