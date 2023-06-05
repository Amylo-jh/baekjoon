#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve()
{
    int n, k, w;
    int total_time = 0;
    cin >> n >> k;

    //time, in_degree
    vector <pair <int, vector <int>>> build(n+1);
    vector <int> in_degree(n+1);
    vector <bool> visited(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> build[i].first;
    }
    for(int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        build[a].second.push_back(b);
        in_degree[b]++;
    }
    cin >> w;

    //time, node;
    priority_queue <pair <int, int>, vector<pair<int, int>>, greater<pair<int, int>> > dag_queue;
    for(int i = 1; i <= n; i++)
    {
        if(in_degree[i] == 0)
        {
            dag_queue.push({build[i].first, i});
            visited[i] = true;
        }
    }

    while(!dag_queue.empty())
    {
        int curr_node = dag_queue.top().second;
        int build_time = dag_queue.top().first;
        // int build_time = build[curr_node].first;
        dag_queue.pop();

        if(curr_node == w)
        {
            cout << build_time << "\n";
            break;
        }

        for(int next_node : build[curr_node].second)
        {
            in_degree[next_node]--;

            if(in_degree[next_node] == 0)
            {
                visited[next_node] = true;
                dag_queue.push({build_time + build[next_node].first, next_node});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--)
    {
        solve();
    }
}