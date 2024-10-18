#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

vector <int> parent;

int find_parent(int a)
{
    if(parent[a] == a)
    {
        return a;
    }
    
    return parent[a] = find_parent(parent[a]);
}

void make_union(int a, int b)
{
    int pa = find_parent(a);
    int pb = find_parent(b);

    if(pa < pb)
    {
        parent[pb] = pa;
    }
    else
    {
        parent[pa] = pb;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector <pair <int, int>> coordinate(n+1);
    vector <vector <double>> dist(n+1, vector <double>(n+1));
    vector <vector <bool>> is_paired(n+1, vector <bool>(n+1, false));
    priority_queue <pair <double, pair <int, int>>> queue;
    parent.resize(n+1);

    for(int i = 1; i <= n; i++)
    {
        cin >> coordinate[i].first >> coordinate[i].second;
        parent[i] = i;
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        is_paired[a][b] = true;
        make_union(a, b);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            double temp_dist = pow(coordinate[i].first - coordinate[j].first, 2) + pow(coordinate[i].second - coordinate[j].second, 2);
            dist[i][j] = sqrt(temp_dist);
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            if(!is_paired[i][j])
            {
                queue.push({-dist[i][j], {i, j}});
            }
        }
    }

    double new_dist = 0;
    while(!queue.empty())
    {
        double next_dist = -queue.top().first;
        int node_a = queue.top().second.first;
        int node_b = queue.top().second.second;
        int pa = find_parent(node_a);
        int pb = find_parent(node_b);
        queue.pop();

        if(pa != pb)
        {
            new_dist += next_dist;
            make_union(pa, pb);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << new_dist;
}