#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int n, d, c;
        cin >> n >> d >> c;
        vector <vector <pair <int, int>>> graph(n+1);
        for(int i = 0; i < d; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            graph[b].push_back({a, c});
        }

        vector <int> dist(n+1, INT32_MAX);
        vector <bool> visited(n+1, false);
        priority_queue <pair <int, int>> pq;
        pq.push({0, c});
        dist[c] = 0;
        while(!pq.empty())
        {
            int curr_cost = -pq.top().first;
            int curr_node = pq.top().second;
            visited[curr_node] = true;
            pq.pop();

            for(auto i : graph[curr_node])
            {
                int next_node = i.first;
                int next_cost = i.second + curr_cost;

                if(dist[next_node] > next_cost)
                {
                    dist[next_node] = next_cost;
                    pq.push({-next_cost, next_node});
                }
            }
        }

        int infected_node = 0;
        int last_time = 0;

        for(int i = 1; i <= n; i++)
        {
            if(dist[i] != INT32_MAX)
            {
                infected_node++;
                if(dist[i] > last_time)
                {
                    last_time = dist[i];
                }
            }     
        }

        cout << infected_node << " " << last_time << "\n";
    }
}