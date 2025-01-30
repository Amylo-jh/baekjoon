#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d;
    cin >> n >> d;
    vector <vector <pair <int, int>>> route(d+1);
    vector <int> dist(d+1, 1e9);
    dist[0] = 0;

    for(int i = 0; i < n; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        if(e <= d && e - s > c)
        {
            route[s].push_back({e, c});
        }
    }

    for(int i = 0; i <= d; i++)
    {
        dist[i+1] = min(dist[i+1], dist[i] + 1);
        for(auto next : route[i])
        {
            dist[next.first] = min(dist[next.first], dist[i] + next.second);
        }
    }

    cout << dist[d];
}