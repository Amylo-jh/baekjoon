#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int get_dist(pair <int, int> a, pair <int, int> b)
{
    int dy = abs(a.first - b.first);
    int dx = abs(a.second - b.second);

    return dy+dx;
}

void solve()
{
    int n;
    cin >> n;
    vector <pair <int, int>> convenience(n+1);
    vector <bool> visited(n+1);
    pair <int, int> end;

    for(int i = 0; i < n+1; i++)
    {
        cin >> convenience[i].first >> convenience[i].second;
    }    
    cin >> end.first >> end.second;

    queue <pair <int, int>> bfs_queue;
    bfs_queue.push(convenience[0]);
    visited[0] = true;

    bool flag = false;
    while(!bfs_queue.empty())
    {
        pair <int, int> curr_pos = bfs_queue.front();
        bfs_queue.pop();

        if(get_dist(curr_pos, end) <= 1000)
        {
            flag = true;
            break;
        }
        for(int i = 0; i < n+1; i++)
        {
            if(!visited[i])
            {
                if(get_dist(curr_pos, convenience[i]) <= 1000)
                {
                    visited[i] = true;
                    bfs_queue.push(convenience[i]);
                }
            }
        }
    }

    if(flag)
    {
        cout << "happy" << "\n";
    }
    else
    {
        cout << "sad" << "\n";
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