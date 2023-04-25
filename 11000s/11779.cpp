#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, Start, End;
vector <vector <pair <int, int>>> edge;
vector <int> dijk;
vector <int> route;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    edge.resize(n+1);
    dijk.resize(n+1);
    dijk.assign(n+1, INT32_MAX);
    route.resize(n+1);
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }
    cin >> Start >> End;

    priority_queue <pair <int, int>> pq;
    pq.push({0, Start});
    dijk[Start] = 0;
    route[Start] = 0;

    while(!pq.empty())
    {
        int curr_cost = -pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if(curr_cost > dijk[curr_node])
        {
            continue;
        }

        for(int i = 0; i < edge[curr_node].size(); i++)
        {
            int next_node = edge[curr_node][i].first;
            int next_cost = edge[curr_node][i].second;

            if(dijk[next_node] > curr_cost + next_cost)
            {
                dijk[next_node] = curr_cost + next_cost;
                route[next_node] = curr_node;
                pq.push({-dijk[next_node], next_node});
            }
        }
    }

    cout << dijk[End] << "\n";

    vector <int> route_result;
    int temp = End;
    while(temp)
    {
        route_result.push_back(temp);
        temp = route[temp];
    }
    cout << route_result.size() << "\n";
    
    for(int i = route_result.size() - 1; i >= 0; i--)
    {
        cout << route_result[i] << " ";
    }
    cout << "\n";
}