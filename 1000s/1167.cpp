#include <iostream>
#include <vector>

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    visited.resize(n+1);
    nodes.resize(n+1);

    for(int i = 1; i <= n; i++)
    {
        int n, next_node = 1, distance;
        cin >> n;

        while(next_node > 0)
        {
            cin >> next_node;
            if(next_node < 0)
            {
                break;
            }
            cin >> distance;

            nodes[n].next_node.push_back({next_node, distance});
            nodes[n].next_node_count++;
            nodes[next_node].next_node.push_back({n, distance});
            nodes[next_node].next_node_count++;
        }
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