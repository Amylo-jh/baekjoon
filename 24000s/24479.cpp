#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector <set <int>> graph;
vector <bool> visited;
vector <int> visit_sequence;

int dfs(int start_dot, int sequence)
{
    if(!visited[start_dot])
    {
        visit_sequence[start_dot] = sequence;
        visited[start_dot] = true;
        for (auto &&i : graph[start_dot])
        {
            if(!visited[i])
            {
                sequence++;
                sequence = dfs(i, sequence);
            }           
        }
    }

    return sequence;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dot, line, start_dot;
    cin >> dot >> line >> start_dot;

    for(int i = 0; i <= dot; i++)
    {
        set <int> temp_set;
        graph.push_back(temp_set);
        visited.push_back(false);
        visit_sequence.push_back(0);
    }

    for(int i = 0; i < line; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    dfs(start_dot, 1);

    for(int i = 1; i <= dot; i++)
    {
        cout << visit_sequence[i] << '\n';
    }
}