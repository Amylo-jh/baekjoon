#include <iostream>
#include <vector>
#include <queue>


using namespace std;

vector <priority_queue<int>> graph;
vector <bool> visited;
vector <int> travel_sequence;

int dfs(int r, int sequence)
{
    visited[r] = true;
    travel_sequence[r] = sequence;
    sequence++;

    while(!graph[r].empty())
    {
        int next_dot = graph[r].top();
        graph[r].pop();
        if(visited[next_dot])
        {
            continue;
        }
        else
        {
            sequence = dfs(next_dot, sequence);
        }
    }

    return sequence;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    for(int i = 0; i <= n; i++)
    {
        priority_queue <int> temp_queue;
        graph.push_back(temp_queue);
        visited.push_back(false);
        travel_sequence.push_back(0);
    }

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push(b);
        graph[b].push(a);
    }

    int sequence = 1;
    dfs(r, sequence);

    for(int i = 1; i <= n; i++)
    {
        cout << travel_sequence[i] << "\n";
    }
}