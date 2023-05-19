#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector <vector <pair <int, int>>> island(n+1);
    vector <bool> visited(n+1);
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        island[a].push_back({b, c});
        island[b].push_back({a, c});
    }

    for(int i = 1; i <= n; i++)
    {
        sort(island[i].begin(), island[i].end(), greater<>());
    }

    int start_island, end_island;
    cin >> start_island >> end_island;

    // weight, node
    priority_queue <pair <int, int>> bfs_queue;
    for(int i = 0; i < island[start_island].size(); i++)
    {
        int next_island = island[start_island][i].first;
        int next_weight = island[start_island][i].second;
        if(!visited[next_island])
        {
            bfs_queue.push({next_weight, next_island});
        }
    }
    visited[start_island] = true;

    int result = 0;
    while(!bfs_queue.empty())
    {
        int curr_weight = bfs_queue.top().first;
        int curr_island = bfs_queue.top().second;
        bfs_queue.pop();
        visited[curr_island] = true;

        if(curr_island == end_island)
        {
            result = curr_weight;
            break;
        }
        
        for(int i = 0; i < island[curr_island].size(); i++)
        {
            int next_island = island[curr_island][i].first;
            int next_weight = island[curr_island][i].second;

            if(!visited[next_island])
            {
                next_weight = min(next_weight, curr_weight);
                bfs_queue.push({next_weight, next_island});
            }
        }
    }

    cout << result;
}