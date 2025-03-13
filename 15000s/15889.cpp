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
    vector <int> pos(n);
    vector <int> range(n-1);
    vector <bool> visited(n);
    queue <int> q;
    for(int i = 0; i < n; i++)
    {
        cin >> pos[i];
    }
    for(int i = 0; i < n-1; i++)
    {
        cin >> range[i];
    }

    q.push(0);
    visited[0] = true;
    bool flag = false;
    while(!q.empty())
    {
        int cur_idx = q.front();
        if(cur_idx == n-1)
        {
            flag = true;
            break;
        }

        int cur_pos = pos[cur_idx];
        int cur_range = range[cur_idx];
        q.pop();

        for(int i = cur_idx+1; i < n; i++)
        {
            if(visited[i])
            {
                continue;
            }
            else if(cur_pos + cur_range >= pos[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    if(flag)
    {
        cout << "권병장님, 중대장님이 찾으십니다";
    }
    else
    {
        cout << "엄마 나 전역 늦어질 것 같아";
    }
}