#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <pair <int, int>>> dist;
vector <int> d;


void dijkstra(int start)
{
    for(int i = 0; i < d.size(); i++)
    {
        d[i] = INT32_MAX;
    }

    d[start] = 0;
    priority_queue <pair <int, int>> pq;
    pq.push({0, start});
    
    while(!pq.empty())
    {
        int curr_dist = -pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        for(int i = 0; i < dist[curr_node].size(); i++)
        {
            int next_node = dist[curr_node][i].first;
            int next_dist = curr_dist + dist[curr_node][i].second;

            if(next_dist < d[next_node])
            {
                d[next_node] = next_dist;
                pq.push({-next_dist, next_node});
            }
        }
    }
}

int main()
{
    int v, e, p;
    cin >> v >> e >> p;
    dist.resize(v+1);
    d.resize(v+1);

    for(int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a;
        b;
        dist[a].push_back({b, c});
        dist[b].push_back({a, c});
    }

    dijkstra(1);
    int dist_1 = d[v];
    int dist_2 = d[p];
    dijkstra(p);
    dist_2 += d[v];

    if(dist_1 == dist_2)
    {
        cout << "SAVE HIM";
    }
    else
    {
        cout << "GOOD BYE";
    }
}