#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector <vector <int>> tasks(n+1);
    vector <int> indegree(n+1);
    vector <int> need_times(n+1);
    vector <int> complete_times(n+1, 0);
    complete_times[0] = 0;

    for(int i = 0; i < n; i++)
    {
        int time, next;
        cin >> time >> next;

        need_times[i+1] = time;
        indegree[i+1] = next;
        for(int j = 0; j < next; j++)
        {
            int task;
            cin >> task;
            tasks[task].push_back(i+1);
        }
    }

    // start time, task number
    priority_queue <int, vector <int>> pq;
    for(int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0)
        {
            pq.push(i);
        }
    }

    while(!pq.empty())
    {
        int task = pq.top();
        int start_time = complete_times[task];
        pq.pop();

        complete_times[task] += need_times[task];

        for(int next_task : tasks[task])
        {
            indegree[next_task]--;
            complete_times[next_task] = max(complete_times[next_task], complete_times[task]);
            if(indegree[next_task] == 0)
            {
                pq.push(next_task);
            }
        }
    }

    int complete_time = 0;
    for(int i = 1; i <= n; i++)
    {
        complete_time = max(complete_time, complete_times[i]);
    }

    cout << complete_time << endl;
}