#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector <vector <int>> computer(n+1);
    vector <int> info(n+1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        computer[b].push_back(a);
    }

    int max_computer = 0;
    for(int i = 1; i <= n; i++)
    {
        vector <bool> visited(n+1);
        queue <int> bfs_queue;
        bfs_queue.push(i);
        visited[i] = true;
        int count = 1;

        while(!bfs_queue.empty())
        {
            int curr_comp = bfs_queue.front();
            bfs_queue.pop();

            for(int j = 0; j < computer[curr_comp].size(); j++)
            {
                if(!visited[computer[curr_comp][j]])
                {
                    bfs_queue.push(computer[curr_comp][j]);
                    visited[computer[curr_comp][j]] = true;
                    count++;
                }
            }

            if(bfs_queue.empty())
            {
                info[i] = count;
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        max_computer = max(max_computer, info[i]);
    }

    for(int i = 1; i <= n; i++)
    {
        if(info[i] == max_computer)
        {
            cout << i << " ";
        }
    }
}