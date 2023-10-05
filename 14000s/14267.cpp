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
    vector <vector <int>> tree(n+1);
    vector <int> credit(n+1);
    vector <bool> visited(n+1);
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if(temp < 0)
        {
            continue;
        }

        tree[temp].push_back(i);
    }
    for(int i = 0; i < m; i++)
    {
        int j, w;
        cin >> j >> w;
        credit[j] += w;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            queue <int> bfs_queue;
            bfs_queue.push(i);
            while(!bfs_queue.empty())
            {
                int node = bfs_queue.front();
                int cred = credit[node];
                bfs_queue.pop();
                visited[node] = true;

                for(int j = 0; j < tree[node].size(); j++)
                {
                    credit[tree[node][j]] += cred;
                    bfs_queue.push(tree[node][j]);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << credit[i] << " ";
    }
}