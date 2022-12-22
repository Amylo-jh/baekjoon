#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <vector <bool>> visited;    
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        visited[i].resize(n);
    }

    int d_r[6] = {-2, -2, 0, 0, 2, 2};
    int d_c[6] = {-1, 1, -2, 2, -1, 1};
    queue <pair <int, int>> bfs_queue1;
    queue <pair <int, int>> bfs_queue2;
    int r1, c1, r2, c2;
    int count = 0;
    bool flag = false;

    cin >> r1 >> c1 >> r2 >> c2;

    visited[r1][c1] = true;
    bfs_queue1.push({r1, c1});

    while(!bfs_queue1.empty())
    {
        int curr_r = bfs_queue1.front().first;
        int curr_c = bfs_queue1.front().second;
        bfs_queue1.pop();
        visited[curr_r][curr_c] = true;

        if(curr_r == r2 && curr_c == c2)
        {
            flag = true;
            break;
        }

        for(int i = 0; i < 6; i++)
        {
            int dr = curr_r + d_r[i];
            int dc = curr_c + d_c[i];

            if(0 <= dr && dr < n && 0 <= dc && dc < n && !visited[dr][dc])
            {
                bfs_queue2.push({dr, dc});
                visited[dr][dc] = true;
            }
        }

        if(bfs_queue1.empty())
        {
            bfs_queue1 = bfs_queue2;
            bfs_queue2 = {};
            count++;
        }
    }
    
    if(flag)
    {
        cout << count;
    }
    else
    {
        cout << -1;
    }
}