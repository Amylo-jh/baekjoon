#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d;
    cin >> n >> d;

    vector <pair <int, int>> alarm(n);
    vector <int> alarm_count(n);
    for(int i = 0; i < n; i++)
    {
        cin >> alarm[i].second >> alarm[i].first;

        int initial_count = d / alarm[i].first;
        initial_count++;
        int delay_count = max(0, alarm[i].second-1) / alarm[i].first;
        if(alarm[i].second != 0)
        {
            delay_count++;
        }

        alarm_count[i] = max(0, initial_count - delay_count);
    }

    int max_alarm = 0;
    pair <int, int> max_alarm_pair = {0, 0};
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            long long lcm_time = lcm(alarm[i].first, alarm[j].first);
            long long lcm_delay = max(alarm[i].second, alarm[j].second);
            
            int lcm_count = d / lcm_time;
            lcm_count++;
            lcm_count -= max(0LL, lcm_delay-1) / lcm_time;
            if(lcm_delay != 0)
            {
                lcm_count--;
            }
            lcm_count = max(0, lcm_count);

            int result_alarm_count = alarm_count[i] + alarm_count[j] - lcm_count;
            if(max_alarm < result_alarm_count)
            {
                max_alarm = result_alarm_count;
                max_alarm_pair = {i, j};
            }
        }
    }

    cout << max_alarm_pair.first+1 << " " << max_alarm_pair.second+1 << "\n" << max_alarm;
}