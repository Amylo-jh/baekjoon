#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int n, m, w;
        cin >> n >> m >> w;

        vector<pair <pair <int, int>, int>> adj;
        vector <int> dist(n+1, 1e9);
        vector <int> visited(n+1, 0);

        for(int i = 0; i < m; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            adj.push_back({{s, e}, t});
            adj.push_back({{e, s}, t});
        }
        for(int i = 0; i < w; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            adj.push_back({{s, e}, -t});
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < adj.size(); j++)
            {
                int s = adj[j].first.first;
                int e = adj[j].first.second;
                int t = adj[j].second;

                if(dist[s] + t < dist[e])
                {
                    dist[e] = dist[s] + t;
                }
            }
        }

        bool is_cycle = false;
        for(int i = 0; i < adj.size(); i++)
        {
            int s = adj[i].first.first;
            int e = adj[i].first.second;
            int t = adj[i].second;

            if(dist[s] + t < dist[e])
            {
                is_cycle = true;
                break;
                
            }
        }

        if(is_cycle)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}