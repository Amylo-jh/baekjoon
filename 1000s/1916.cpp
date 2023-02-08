#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;

    vector <vector <pair <int, int>> > graph(n);
    vector <int> d(n);
    d.assign(n, INT32_MAX);
    for(int i = 0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        start--;
        end--;
        graph[start].push_back({end, cost});
    }
    cin >> a >> b;
    a--;
    b--;

    d[a] = 0;
    priority_queue <pair <int, int>> pq;
    pq.push({a, 0});

    while(!pq.empty())
    {
        int current = pq.top().first;
        int dist = -pq.top().second;
        pq.pop();

        if(d[current] < dist)
        {
            continue;
        }

        for(int i = 0; i < graph[current].size(); i++)
        {
            int next_node = graph[current][i].first;
            int next_dist = dist + graph[current][i].second;
            if(next_dist < d[next_node])
            {
                d[next_node] = next_dist;
                pq.push({next_node, -next_dist});
            }
        }
    }

    cout << d[b];
}