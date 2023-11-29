#include <iostream>
#include <vector>
#include <array>

using namespace std;

int v, e;
int intmax = INT32_MAX-10000;
vector <array <int, 3>> edge;
vector <long long> dist;
    
bool bellman_ford(int start)
{
    bool is_negative_cycle = false;
    dist[start] = 0;

    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < e; j++)
        {
            int curr_node = edge[j][0];
            int next_node = edge[j][1];
            int cost = edge[j][2];

            if(dist[curr_node] != intmax && dist[next_node] > dist[curr_node] + cost)
            {
                dist[next_node] = dist[curr_node] + cost;
                if(i == v-1)
                {
                    is_negative_cycle = true;
                }
            }
        }
    }

    return is_negative_cycle;
}

int main()
{
    cin >> v >> e;

    edge.resize(e);
    dist.resize(v+1);
    dist.assign(v+1, intmax);

    for(int i = 0; i < e; i++)
    {
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
    }

    bool is_negative_cycle = bellman_ford(1);

    if(is_negative_cycle)
    {
        cout << -1;
    }
    else
    {
        for(int i = 2; i <= v; i++)
        {
            if(dist[i] != intmax)
            {
                cout << dist[i];
            }
            else
            {
                cout << -1;
            }
            cout << "\n";
        }
    }
}