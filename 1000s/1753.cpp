#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e, start_point;
    cin >> v >> e >> start_point;

    //weight, end;
    vector <vector <pair <int, int>> > graph(v+1);
    vector <int> dijk(v+1);
    dijk.assign(v+1, INT32_MAX);

    for(int i = 0; i < e; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        graph[start].push_back({weight, end});
    }

    //weight, curr_node;
    priority_queue <pair <int, int>> pq;
    pq.push({0, start_point});
    dijk[start_point] = 0;

    while(!pq.empty())
    {
        int curr_node = pq.top().second;
        int curr_dist = -pq.top().first;
        pq.pop();

        if(dijk[curr_node] < curr_dist)
        {
            continue;
        }

        for(int i = 0; i < graph[curr_node].size(); i++)
        {
            int next_node = graph[curr_node][i].second;
            int next_dist = curr_dist + graph[curr_node][i].first;

            if(next_dist < dijk[next_node])
            {
                dijk[next_node] = next_dist;
                pq.push({-next_dist, next_node});
            }
        }
    }

    for(int i = 1; i <= v; i++)
    {
        if(dijk[i] == INT32_MAX)
        {
            cout << "INF\n";
        }
        else
        {
            cout << dijk[i] << "\n";
        }
    }
}