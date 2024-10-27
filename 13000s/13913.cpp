#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector <int> time(100001, INT32_MAX);
    vector <int> route(100001);

    queue <pair <int, int>> bfs_queue;
    bfs_queue.push({n, 0});
    time[n] = 0;

    while(!bfs_queue.empty())
    {
        int curr_node = bfs_queue.front().first;
        int curr_time = bfs_queue.front().second;
        bfs_queue.pop();

        if(curr_node == m)
        {
            cout << curr_time << "\n";
            break;
        }

        if(0 <= curr_node-1 && time[curr_node-1] > curr_time+1)
        {
            time[curr_node-1] = curr_time+1;
            route[curr_node-1] = curr_node;
            bfs_queue.push({curr_node-1, curr_time+1});
        }
        if(curr_node+1 <= 100000 && time[curr_node+1] > curr_time+1)
        {
            time[curr_node+1] = curr_time+1;
            route[curr_node+1] = curr_node;
            bfs_queue.push({curr_node+1, curr_time+1});
        }
        if(curr_node*2 <= 100000 && time[curr_node*2] > curr_time+1)
        {
            time[curr_node*2] = curr_time+1;
            route[curr_node*2] = curr_node;
            bfs_queue.push({curr_node*2, curr_time+1});
        }
    }

    vector <int> path;
    for(int i = m; i != n; i = route[i])
    {
        path.push_back(i);
    }
    path.push_back(n);

    for(int i = path.size()-1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
}