#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> ant;
vector<int> level;
vector<vector<pair<int, int>>> graph;
vector <vector <int>> parent(100001, vector <int>(20));
vector <vector <int>> cost(100001, vector <int>(20));

void initgraph()
{
    level[1] = 0;
    // curr, level
    queue<pair<int, int>> bfs_queue;
    bfs_queue.push({1, 0});
    while (!bfs_queue.empty())
    {
        auto [curr, curr_level] = bfs_queue.front();
        bfs_queue.pop();
        for (auto [next, dist] : graph[curr])
        {
            if (level[next] == 0 && next != 1)
            {
                bfs_queue.push({next, curr_level + 1});
                level[next] = curr_level + 1;
                parent[next][0] = curr;
                cost[next][0] = dist;
            }
        }
    }
}

void sparse()
{
    parent[1][0] = 1;
    cost[1][0] = 0;

    for(int i = 1; i < 20; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            parent[j][i] = parent[parent[j][i-1]][i-1];
            cost[j][i] = cost[j][i-1] + cost[parent[j][i-1]][i-1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    ant.resize(n+1);
    level.resize(n+1);
    graph.resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> ant[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    initgraph();
    sparse();

    for(int i = 1; i <= n; i++)
    {
        int tmp = i;
        for(int j = 19; j >= 0; j--)
        {
            if(cost[tmp][j] <= ant[i])
            {
                ant[i] -= cost[tmp][j];
                tmp = parent[tmp][j];
            }
        }
        cout << tmp << "\n";
    }
}