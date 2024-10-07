#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c;
    cin >> n >> c;

    // portal_type, end
    vector <pair <int, int>> arr(n);
    vector <int> dp(n, INT32_MAX);
    for(int i = 0; i < n; i++)
    {
        arr[i].first = 0;
        arr[i].second = i;
    }
    for(int i = 0; i < c; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;

        if(t == 1)
        {
            arr[a].first = 1;
        }
        else
        {
            arr[a].first = 2;
        }
        arr[a].second = b;
    }

    priority_queue <pair <int, int>> bfs_queue;
    bfs_queue.push({0, 0});
    dp[0] = 0;

    while(!bfs_queue.empty())
    {
        int time = -bfs_queue.top().first;
        int pos = bfs_queue.top().second;
        bfs_queue.pop();

        if(pos == n-1)
        {
            continue;
        }
        if(time > n)
        {
            continue;
        }

        if(arr[pos].first == 1)
        {
            if(time < dp[arr[pos].second])
            {
                dp[arr[pos].second] = time;
                bfs_queue.push({-time, arr[pos].second});
            }
            if(time+1 < dp[pos+1])
            {
                dp[pos+1] = time+1;
                bfs_queue.push({-(time+1), pos+1});
            }
        }
        else if(arr[pos].first == 2)
        {
            if(time < dp[arr[pos].second])
            {
                dp[arr[pos].second] = time;
                bfs_queue.push({-time, arr[pos].second});
            }
        }
        else if(time+1 < dp[pos+1])
        {
            dp[pos+1] = time+1;
            bfs_queue.push({-(time+1), pos+1});
        }
    }

    if(dp[n-1] == INT32_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << dp[n-1];
    }
}