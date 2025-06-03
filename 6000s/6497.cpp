#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0)
        {
            break;
        }

        vector <vector <pair <int, int>>> graph(n);
        vector <bool> visited(n, false);
        int sum = 0;
        int used_sum = 0;
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
            sum += c;
        }
    
        // -cost, next
        priority_queue <pair <int, int>> pq;
        for(auto i : graph[0])
        {
            pq.push({-i.second, i.first});
        }
    
        visited[0] = true;
        while(!pq.empty())
        {
            int dist = -pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            if(visited[curr])
            {
                continue;
            }

            used_sum += dist;
            visited[curr] = true;
            for(auto i : graph[curr])
            {
                int next_node = i.first;
                int next_dist = i.second;
                if(visited[next_node] == false)
                {
                    pq.push({-next_dist, next_node});
                }
            }
        }
        cout << sum - used_sum << "\n";
    }
}