#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t, m, l;
    cin >> n >> t >> m >> l;
    vector <vector <array <int, 3>>> path(n+1);
    for(int i = 0; i < l; i++)
    {
        int a, b, time, cost;
        cin >> a >> b >> time >> cost;
        path[a].push_back({b, time, cost});
        path[b].push_back({a, time, cost});
    }

    priority_queue<array <int, 3>> pq;
    // cost, time, node
    vector <vector <int>> cost(n+1, vector <int>(m+1, INT32_MAX));
    pq.push({0, 0, 1});
    cost[1][0] = 0;

    while(!pq.empty())
    {
        int curr_cost = -pq.top()[0];
        int curr_time = -pq.top()[1];
        int curr_node = pq.top()[2];
        pq.pop();

        for(auto i : path[curr_node])
        {
            int next_node = i[0];
            int next_time = i[1] + curr_time;
            int next_cost = i[2] + curr_cost;

            if(next_time <= t && next_cost <= m && next_time < cost[next_node][next_cost])
            {
                cost[next_node][next_cost] = next_time;
                pq.push({-next_cost, -next_time, next_node});
            }
        }
    }

    int min_cost = INT32_MAX;
    for(int i = 0; i <= m; i++)
    {
        if(cost[n][i] <= t)
        {
            cout << i;
            return 0;
        }
    }

    cout << -1;
}