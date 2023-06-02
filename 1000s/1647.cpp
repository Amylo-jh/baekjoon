#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector <int> parent;

int find(int a)
{
    if(a != parent[a])
    {
        parent[a] = find(parent[a]);
    }

    return parent[a];
}

void make_union(int n1, int n2)
{
    int p1 = find(n1);
    int p2 = find(n2);

    if(p1 != p2)
    {
        parent[p2] = p1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    parent.resize(n+1);
    priority_queue <pair <int, pair <int, int>>> pq;

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        pq.push({-c,{a, b}});
    }
    for(int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    int total_cost = 0;
    int last_cost = 0;
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int node1 = pq.top().second.first;
        int node2 = pq.top().second.second;
        pq.pop();

        int parent1 = find(node1);
        int parent2 = find(node2);

        if(parent1 == parent2)
        {
            continue;    
        }

        make_union(node1, node2);
        total_cost += cost;
        last_cost = cost;
    }

    total_cost -= last_cost;
    cout << total_cost;
}