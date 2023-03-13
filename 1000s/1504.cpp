#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector <vector <pair <int, int>> > graph;
vector <int> d;
int n, e;
int max_dist_value = 10000000;

class Compare {
public:
    bool operator() (pair <int, int> a, pair <int, int> b)
    {
        return a.second > b.second;
    }
};

void reset_dijk()
{
    for(int i = 0; i <= n; i++)
    {
        d[i] = max_dist_value;
    }
}

int dijkstra(int start, int end)
{
    d[start] = 0;
    priority_queue <pair <int, int>, vector<pair<int, int>>, Compare> pq;
    pq.push({start, 0});

    while(!pq.empty())
    {
        int curr_node = pq.top().first;
        int curr_dist = pq.top().second;
        pq.pop();

        if(d[curr_node] < curr_dist)
        {
            continue;
        }
        
        for(int i = 0; i < graph[curr_node].size(); i++)
        {
            int next_node = graph[curr_node][i].first;
            int next_dist = graph[curr_node][i].second + curr_dist;

            if(next_dist < d[next_node])
            {
                d[next_node] = next_dist;
                pq.push({next_node, next_dist});
            }
        }
    }

    return d[end];
}

int main()
{
    
    cin >> n >> e;
    graph.resize(n+1);
    d.resize(n+1);

    for(int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int dest_1[4] = {1, 0, 0, n};
    cin >> dest_1[1] >> dest_1[2];
    int dest_2[4] = {1, dest_1[2], dest_1[1], n};

    int total_dist_1 = 0;
    bool flag_1 = true;
    for(int i = 0; i < 3; i++)
    {
        reset_dijk();
        long long curr_dist = dijkstra(dest_1[i], dest_1[i+1]);

        if(curr_dist == max_dist_value)
        {
            total_dist_1 = INT32_MAX;
            flag_1 = false;
            break;
        }
        else
        {
            total_dist_1 += curr_dist;
        }
    }

    int total_dist_2 = 0;
    bool flag_2 = true;
    for(int i = 0; i < 3; i++)
    {
        reset_dijk();
        long long curr_dist = dijkstra(dest_2[i], dest_2[i+1]);

        if(curr_dist == max_dist_value)
        {
            total_dist_2 = INT32_MAX;
            flag_2 = false;
            break;
        }
        else
        {
            total_dist_2 += curr_dist;
        }
    }

    if(!flag_1 && !flag_2)
    {
        cout << -1;
    }
    else
    {
        cout << min(total_dist_1, total_dist_2);
    }
}