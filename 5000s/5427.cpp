#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int n, m;
        cin >> m >> n;

        int dy[4] = {-1, 0, 1, 0};
        int dx[4] = {0, 1, 0, -1};
        // 0 = empty place, 1 = wall, 0 = start, 1 = fire
        vector <vector <int>> area(n);
        vector <vector <bool>> visited(n);

        //seqeunce, y, x
        queue <pair <int, pair <int, int>>> fire_queue;
        queue <pair <int, pair <int, int>>> bfs_queue;

        for(int i = 0; i < n; i++)
        {
            area[i].resize(m);
            visited[i].resize(m);

            string str;
            cin >> str;
            for(int j = 0; j < m; j++)
            {
                if(str[j] == '.')
                {
                    area[i][j] = 0;
                }
                else if(str[j] == '#')
                {
                    area[i][j] = 1;
                }
                else if(str[j] == '@')
                {
                    area[i][j] = 0;
                    bfs_queue.push({1, {i, j}});
                    visited[i][j] = true;
                }
                else if(str[j] == '*')
                {
                    area[i][j] = 1;
                    fire_queue.push({1, {i, j}});
                }
            }
        }

        bool flag = false;
        int seq = 1;
        int result = 0;
        while(!bfs_queue.empty())
        {
            int curr_seq = bfs_queue.front().first;
            int curr_y = bfs_queue.front().second.first;
            int curr_x = bfs_queue.front().second.second;
            bfs_queue.pop();

            if(curr_seq != seq)
            {
                seq++;
            }

            queue <pair <int, int>> curr_fire_queue;
            while(fire_queue.front().first == seq)
            {
                curr_fire_queue.push({fire_queue.front().second});
                fire_queue.pop();

                while(!curr_fire_queue.empty())
                {
                    int curr_fire_y = curr_fire_queue.front().first;
                    int curr_fire_x = curr_fire_queue.front().second;
                    curr_fire_queue.pop();

                    for(int i = 0; i < 4; i++)
                    {
                        int y = curr_fire_y + dy[i];
                        int x = curr_fire_x + dx[i];

                        if(0 <= y && y < n && 0 <= x && x < m && area[y][x] != 1)
                        {
                            area[y][x] = 1;
                            fire_queue.push({seq+1, {y, x}});
                        }
                    }
                }
            }
            
            for(int i = 0; i < 4; i++)
            {
                int y = curr_y + dy[i];
                int x = curr_x + dx[i];

                if(!(0 <= y && y < n && 0 <= x && x < m))
                {
                    result = seq;
                    flag = true;
                    bfs_queue = {};
                    break;
                }

                if(0 <= y && y < n && 0 <= x && x < m && !visited[y][x] && area[y][x] != 1)
                {
                    bfs_queue.push({seq+1, {y, x}});
                    visited[y][x] = true;
                }
            }
        }

        if(flag)
        {
            cout << result << "\n";
        }
        else
        {
            cout << "IMPOSSIBLE\n";
        }
    }
}