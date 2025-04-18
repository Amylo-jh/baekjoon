#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
vector <vector <pair <int, int>>> edge;
vector <int> interviewroom;
vector <long long> dist;
vector <bool> visited;

void dijkstra()
{
    priority_queue <pair <long long, int>> pq;
    for(int i = 0; i < k; i++)
    {
        pq.push({0, interviewroom[i]});
        dist[interviewroom[i]] = 0;
    }

    while(!pq.empty())
    {
        long long curr_dist = -pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if(visited[curr_node])
        {
           continue; 
        }
        visited[curr_node] = true;

        for(auto i : edge[curr_node])
        {
            int next_node = i.first;
            long long next_dist = curr_dist + i.second;
            if(dist[next_node] > next_dist)
            {
                dist[next_node] = next_dist;
                pq.push({-next_dist, next_node});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    edge.resize(n+1);
    interviewroom.resize(n+1);
    dist.resize(n+1, INT64_MAX);
    visited.resize(n+1, false);
    
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[b].push_back({a, c});
    }
    for(int i = 0; i < k; i++)
    {
        cin >> interviewroom[i];
    }

    dijkstra();
    long long answer_node = 1, answer_dist = 0;
    for(int i = 1; i <= n; i++)
    {
        if(answer_dist < dist[i])
        {
            answer_node = i;
            answer_dist = dist[i];
        }
    }

    cout << answer_node << "\n" << answer_dist;
}