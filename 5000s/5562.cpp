#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    cin >> n >> l;
    vector <int> arr(n);
    vector <int> waiting(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // curr_time, len, idx
    priority_queue <pair <int, pair <int, int>>> pq;
    for(int i = 0; i < n; i++)
    {
        if(arr[max(0, i-1)] <= arr[i] && arr[i] >= arr[min(n-1, i+1)])
        {
            pq.push({0, {arr[i], i}});
        }

        if(arr[max(0, i-1)] > arr[i])
        {
            waiting[i]++;
        }
        if(arr[i] < arr[min(n-1, i+1)])
        {
            waiting[i]++;
        }
    }

    int time = 0;
    while(!pq.empty())
    {
        auto p = pq.top();
        int curr_time = -p.first;
        int curr_len = p.second.first;
        int curr_idx = p.second.second;
        pq.pop();

        int dt = l - curr_len;
        int next_time = curr_time + dt;
        time = max(time, next_time);

        if(curr_idx-1 >= 0)
        {
            waiting[curr_idx-1]--;
            if(waiting[curr_idx-1] == 0)
            {
                pq.push({-next_time, {arr[curr_idx-1], curr_idx-1}});
            }
        }
        if(curr_idx+1 < n)
        {
            waiting[curr_idx+1]--;
            if(waiting[curr_idx+1] == 0)
            {
                pq.push({-next_time, {arr[curr_idx+1], curr_idx+1}});
            }
        }
    }

    cout << time;
}