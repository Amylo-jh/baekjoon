#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long n, m, c;
long long max_value = 9e10;

vector <pair <long long, int>> dist;
// vector <bool> repair;
bool repair[100001];
vector <vector <pair <int, int>>> vertex;

void dijk()
{
    priority_queue< pair <long long, int>> pq;
    pq.push({0, 1});

    while(!pq.empty())
    {
        long long curr_cost = -pq.top().first;
        int curr_node = pq.top().second;    
        pq.pop();

        if(dist[curr_node].first < curr_cost)
        {
            continue;
        }

        for(pair <int, int> p : vertex[curr_node])
        {
            long long next_cost = p.first;
            int next_node = p.second;

            if(dist[next_node].first > curr_cost + next_cost)
            {
                dist[next_node].first = curr_cost + next_cost;
                pq.push({-dist[next_node].first, next_node});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long total_dist = 0;
    cin >> n >> m >> c;
    dist.resize(n+1);
    vertex.resize(n+1);

    for(int i = 0; i < m; i++)
    {   
        int a, b, c;
        cin >> a >> b >> c;
        vertex[a].push_back({c, b});
        vertex[b].push_back({c, a});
        total_dist += c;
    }

    for(int i = 0; i <= n; i++)
    {
        dist[i] = {max_value, i};
    }
    dist[1] = {0, 1};
    dijk();
    sort(dist.begin(), dist.end());

    long long min_cost = max_value;
    long long total_repair_cost = 0;
    for(int i = 0; i < n; i++)
    {
        int curr_node = dist[i].second;
        long long curr_cost = dist[i].first;
        repair[curr_node] = true;

        for(pair <int, int> p : vertex[curr_node])
        {
            int next_node = p.second;
            long long next_cost = p.first;

            if(repair[next_node])
            {
                total_repair_cost += next_cost;
            }
        }

        long long compare_cost = c*curr_cost + total_dist-total_repair_cost;
        min_cost = min(min_cost, compare_cost);
    }

    cout << min_cost;
}