#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct node {
    int next_node_count = 0;
    //next_node, distance
    vector <pair <int, int>> next_node;
};

vector <bool> visited;
vector <node> nodes;

int end_point = 0;
int max_distance = 0;
void dfs(int start_point, int distance)
{
    visited[start_point] = true;
    if(max_distance < distance)
    {
        end_point = start_point;
        max_distance = distance;
    }

    for(int i = 0; i < nodes[start_point].next_node_count; i++)
    {
        int next_node = nodes[start_point].next_node[i].first;
        if(!visited[next_node])
        {
            dfs(next_node, distance + nodes[start_point].next_node[i].second);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    
    visited.resize(n+1);
    nodes.resize(n+1);

    for(int i = 1; i < n; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;

        nodes[a].next_node.push_back({b, d});
        nodes[a].next_node_count++;
        nodes[b].next_node.push_back({a, d});
        nodes[b].next_node_count++;
    }

    dfs(1, 0);

    for(int i = 0; i < n+1; i++)
    {
        visited[i] = false;
    }
    max_distance = 0;

    dfs(end_point, 0);

    cout << max_distance;
}