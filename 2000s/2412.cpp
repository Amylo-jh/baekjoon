#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <pair <int, int>> groove;
vector <bool> visited;
int n, t;

bool comp(pair <int, int> a, pair <int, int> b)
{
    return a.first < b.first;
}

int bfs()
{
    // int counter = 0;
    queue <pair <int, int>> bfs_queue;
    queue <int> seq_queue;
    bool flag = false;

    bfs_queue.push({0,0});
    seq_queue.push(0);
    int return_value;

    while(!bfs_queue.empty())
    {
        int curr_y = bfs_queue.front().first;
        int curr_x = bfs_queue.front().second;
        int curr_seq = seq_queue.front();
        
        bfs_queue.pop();
        seq_queue.pop();

        int min_pos = lower_bound(groove.begin(), groove.end(), make_pair(curr_y - 2, 0)) - groove.begin();
        int max_pos = lower_bound(groove.begin(), groove.end(), make_pair(curr_y + 3, 0)) - groove.begin();
        
        for(auto i = min_pos; i < max_pos; i++)
        {
             if(abs(curr_x - groove[i].second) <= 2)
             {
                if(!visited[i])
                {
                    visited[i] =  true;
                    bfs_queue.push({groove[i].first, groove[i].second});
                    seq_queue.push(curr_seq + 1);
                    if(groove[i].first == t)
                    {
                        return curr_seq + 1;
                    }
                }
             }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> t;

    groove.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> groove[i].second >> groove[i].first;
    }    
    sort(groove.begin(), groove.end());

    cout << bfs();
}