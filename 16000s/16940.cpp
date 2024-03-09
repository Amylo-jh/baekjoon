#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector <vector <int>> arr;
vector <int> order;
vector <bool> visit;

bool comp(int a, int b)
{
    return order[a] < order[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    arr.resize(n+1);
    order.resize(n+1);
    visit.resize(n+1);
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        order[x] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        sort(arr[i].begin(), arr[i].end(), comp);
    }

    if(order[1] != 1)
    {
        cout << 0;
        return 0;
    }

    queue <int> bfs_queue;
    bfs_queue.push(1);
    visit[1] = true;
    int seq = 2;
    while(!bfs_queue.empty())
    {
        int top = bfs_queue.front();
        bfs_queue.pop();

        for(int i = 0; i < arr[top].size(); i++)
        {
            int next = arr[top][i];

            if(visit[next])
            {
                continue;
            }

            if(!visit[next] && order[next] == seq)
            {
                seq++;
                visit[next] = true;
                bfs_queue.push(next);
            }
            else if(order[next] != seq)
            {
                cout << 0;
                return 0;
            }
        }
    }

    cout << 1;
}