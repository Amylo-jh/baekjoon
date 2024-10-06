#include <iostream>
#include <vector>
#include <queue>

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
        long long day;
        long long total_day = 1;
        queue <int> q;
        vector <int> interval;
        cin >> day;

        for(int i = 0; i < 7; i++)
        {
            int x;
            cin >> x;
            q.push(x);
        }

        while(!q.front())
        {
            q.push(q.front());
            q.pop();
        }
        q.push(q.front());
        q.pop();
        int interval_size = 1;
        for(int i = 0; i < 7; i++)
        {
            if(q.front() == 1)
            {
                interval.push_back(interval_size);
                interval_size = 0;
            }
            interval_size++;
            q.push(q.front());
            q.pop();
        }

        int class_per_week = interval.size();
        
        int idx = 0;
        int start_idx = 0;
        day--;

        if(day / class_per_week)
        {
            total_day += (day / class_per_week)*7;
            day %= class_per_week;
        }
        while(day)
        {
            day--;
            total_day += interval[idx];
            idx++;
            idx %= class_per_week;
        }

        long long answer = total_day;
        for(int i = 0; i < interval.size(); i++)
        {
            total_day += interval[idx];
            total_day -= interval[start_idx];
            idx++;
            start_idx++;
            idx %= class_per_week;
            start_idx %= class_per_week;
            answer = min(answer, total_day);
        }

        cout << answer << "\n";
    }
}