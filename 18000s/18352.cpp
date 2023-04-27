#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, x;
    cin >> n >> m >> k >> x;

    vector <vector <int>> cities(n+1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cities[a].push_back(b);
    }
    
    vector <int> dijk(n+1);
    dijk.assign(n+1, 500000);
    dijk[x] = 0;
    priority_queue <pair <int, int>> pq;
    pq.push({0, x});

    while(!pq.empty())
    {
        int curr_dist = -pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if(dijk[curr_node] < curr_dist)
        {
            continue;
        }

        for(int i = 0; i < cities[curr_node].size(); i++)
        {
            int next_dist = curr_dist + 1;
            int next_node = cities[curr_node][i];

            if(dijk[next_node] > next_dist)
            {
                dijk[next_node] = next_dist;
                pq.push({-next_dist, next_node});
            }
        }
    }

    bool flag = true;
    for(int i = 0; i <= n; i++)
    {
        if(dijk[i] == k)
        {
            cout << i << "\n";
            flag = false;
        }
    }
    if(flag)
    {
        cout << -1;
    }
}