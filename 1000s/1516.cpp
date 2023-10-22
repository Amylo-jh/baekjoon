#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <vector <int>> arr(n+1);
    vector <int> times(n+1);
    vector <int> total_times(n+1);
    vector <int> input(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> times[i];
        while(1)
        {
            int build;
            cin >> build;
            if(build == -1)
            {
                break;
            }
            else
            {
                arr[build].push_back(i);
                input[i]++;
            }
        }   
    }

    int time = 0;
    queue <pair <int, int>> q;
    for(int i = 1; i <= n; i++)
    {
        if(input[i] == 0)
        {
            q.push({0, i});
        }
    }

    while(!q.empty())
    {
        int time = q.front().first;
        int node = q.front().second;
        q.pop();

        total_times[node] = max(time + times[node], total_times[node] + times[node]);
        for(int i : arr[node])
        {
            input[i]--;
            total_times[i] = max(total_times[i], total_times[node]);
            if(input[i] == 0)
            {
                q.push({total_times[node], i});
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        cout << total_times[i] << "\n";
    }
}