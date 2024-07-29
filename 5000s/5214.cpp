#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, m;
    cin >> n >> k >> m;

    vector <vector <int>> node(n+1);
    vector <vector <int>> tube(m);
    vector <bool> visited(n+1, false);
    vector <bool> visited_tube(m, false);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < k; j++)
        {
            int temp;
            cin >> temp;
            tube[i].push_back(temp);
            node[temp].push_back(i);
        }
    }

    int count = 0;
    queue <int> bfs_queue;
    queue <int> next_queue;
    bfs_queue.push(1);
    visited[1] = true;

    while(!bfs_queue.empty())
    {
        int curr_node = bfs_queue.front();
        bfs_queue.pop();
        if(curr_node == n)
        {
            cout << count+1 << endl;
            return 0;
        }

        for(int i : node[curr_node])
        {
            if(!visited_tube[i])
            {
                visited_tube[i] = true;
                for(int j : tube[i])
                {
                    if(!visited[j])
                    {
                        visited[j] = true;
                        next_queue.push(j);
                    }
                }
            }
        }

        if(bfs_queue.empty())
        {
            count++;
            bfs_queue = next_queue;
            next_queue = {};
        }
    }

    cout << -1 << endl;
}