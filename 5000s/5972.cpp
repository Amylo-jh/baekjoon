#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    //sequence, next_node_number, cost;
    vector <vector <pair <int, int>>> node(n+1);

    while(m--)
    {
        int a, b, cost;
        cin >> a >> b >> cost;

        node[a].push_back({b, cost});
        node[b].push_back({a, cost});
    }

    vector <int> d(n+1);
    d.assign(n+1, INT32_MAX);
    d[1] = 0;
    
    priority_queue<pair <int, int>> pq;
    pq.push({1, 0});

    while(!pq.empty())
    {
        int current = pq.top().first;
        int distance = pq.top().second;
        pq.pop();

        if(d[current] >= distance)
        {
            for(int i = 0; i < node[current].size(); i++)
            {
                int next_node = node[current][i].first;
                int next_dist = distance + node[current][i].second;

                if(next_dist < d[next_node])
                {
                    d[next_node] = next_dist;
                    pq.push({next_node, next_dist});
                }        
            }
        }
    }

    cout << d[n];
}