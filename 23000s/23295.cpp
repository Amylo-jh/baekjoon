#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    cin >> n >> t;
    
    vector <int> time_table(100001);

    for(int i = 0; i < n; i++)
    {
        int time;
        cin >> time;
        for(int j = 0; j < time; j++)
        {
            int start, end;
            cin >> start >> end;
            time_table[start]++;
            time_table[end]--;
        }
    }

    for(int i = 1; i <= 100000; i++)
    {
        time_table[i] += time_table[i-1];
    }

    long long max_value = 0;
    long long curr_value = 0;
    int max_start_time = 0;

    for(int i = 0; i < t; i++)
    {
        curr_value += time_table[i];
    }
    max_value = curr_value;

    for(int i = t; i <= 100000; i++)
    {
        curr_value += time_table[i];
        curr_value -= time_table[i-t];
        if(max_value < curr_value)
        {
            max_value = curr_value;
            max_start_time = i-t + 1;
        }
    }

    cout << max_start_time << " " << max_start_time + t;
}