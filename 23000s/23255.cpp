#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector <int> color(n+1);
    vector <vector <int>> other_color(n+1);
    vector <vector <int>> graph(n+1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
    {
        int curr_color = 1;
        sort(other_color[i].begin(), other_color[i].end());
        for(int j : other_color[i])
        {
            if(j == curr_color)
            {
                curr_color++;
            }
        }
        
        color[i] = curr_color;
        for(int next_node : graph[i])
        {
            other_color[next_node].push_back(curr_color);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << color[i] << " ";
    }
}