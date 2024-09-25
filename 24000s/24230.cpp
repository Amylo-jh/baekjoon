#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector <int> color(n+1);
    vector <int> curr_color(n+1);
    vector <bool> visited(n+1);
    vector <vector <int>> graph(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> color[i];
    }
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int count = 0;
    queue <pair <int, int>> q;
    q.push({1, 0});
    visited[1] = true;

    while(!q.empty())
    {
        int curr_node = q.front().first;
        int curr_color = q.front().second;
        q.pop();

        if(color[curr_node] != curr_color)
        {
            count++;
            curr_color = color[curr_node];
        }
        
        for(int next_node : graph[curr_node])
        {
            if(!visited[next_node])
            {
                visited[next_node] = true;
                q.push({next_node, curr_color});
            }
        }
    }

    cout << count;
}