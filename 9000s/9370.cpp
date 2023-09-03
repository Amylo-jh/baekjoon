#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <pair <int, int>>> graph;
int n, m, t, s, g, h;

int dijkstra(int start, int end)
{
    vector <int> dist(n+1);
    dist.assign(n+1, 10000000);
    dist[start] = 0;
    priority_queue <pair <int, int>> pq;
    pq.push({start, 0});
    while(!pq.empty())
    {
        int curr_node = pq.top().first;
        int curr_dist = -pq.top().second;
        pq.pop();

        if(dist[curr_node] < curr_dist)
        {
            continue;
        }
        for(int i = 0; i < graph[curr_node].size(); i++)
        {
            int next_node = graph[curr_node][i].first;
            int next_dist = curr_dist + graph[curr_node][i].second;
            if(next_dist < dist[next_node])
            {
                dist[next_node] = next_dist;
                pq.push({next_node, -next_dist});
            }
        }
    }

    return dist[end];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m >> t >> s >> g >> h;
        graph = {};
        graph.resize(n+1);
        
        for(int i = 0; i < m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back({b,d});
            graph[b].push_back({a,d});
        }

        vector <int> cities;
        for(int i = 0; i < t; i++)
        {
            int city;
            cin >> city;

            int start, end;
            int start_path, path_length, end_path;
            
            int d_g = dijkstra(s, g);
            int d_h = dijkstra(s, h);
            start_path = min(d_g, d_h);
            if(d_g < d_h)
            {
                start = g;
                end = h;
            }
            else
            {
                start = h;
                end = g;
            }

            path_length = dijkstra(g, h);
            end_path = dijkstra(end, city);
            
            int total_path = start_path + path_length + end_path;
            if(total_path == dijkstra(s, city))
            {
                cities.push_back(city);
            }
        }
        sort(cities.begin(), cities.end());
        
        for(int i = 0; i < cities.size(); i++)
        {
            cout << cities[i] << " ";
        }
        cout << "\n";
    }
}