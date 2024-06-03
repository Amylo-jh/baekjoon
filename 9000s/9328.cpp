#include <iostream>
#include <string>
#include <vector>
#include <queue>

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
        cin >> n >> m;

        vector <vector <int>> arr(n, vector <int> (m));
        vector <vector <bool>> visited(n, vector <bool> (m, false));
        vector <bool> keys(26, false);

        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for(int j = 0; j < m; j++)
            {
                if(s[j] == '*')
                {
                    arr[i][j] = -1;
                }
                else if(s[j] == '.')
                {
                    arr[i][j] = 0;
                }
                else if(s[j] == '$')
                {
                    arr[i][j] = 1000;
                }
                else if('A' <= s[j] && s[j] <= 'Z')
                {
                    arr[i][j] = s[j] - 'A' + 100;
                }
                else if('a' <= s[j] && s[j] <= 'z')
                {
                    arr[i][j] = s[j] - 'a' + 200;
                }
            }
        }

        string init_keys;
        cin >> init_keys;
        if(init_keys != "0")
        {
            for(int i = 0; i < init_keys.size(); i++)
            {
                keys[init_keys[i] - 'a'] = true;
            }
        }

        queue <pair <int, int>> bfs_queue;
        queue <pair <int, pair<int, int>>> door_queue;
        int door_seq = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i][0] != -1)
            {
                if(100 <= arr[i][0] && arr[i][0] <= 125)
                {
                    door_queue.push({door_seq, {i, 0}});
                }
                else
                {
                    bfs_queue.push({i, 0});
                    visited[i][0] = true;
                }
            }
            if(arr[i][m - 1] != -1)
            {
                if(100 <= arr[i][m-1] && arr[i][m-1] <= 125)
                {
                    door_queue.push({door_seq, {i, m - 1}});
                }
                else
                {
                    bfs_queue.push({i, m - 1});
                    visited[i][m - 1] = true;
                }
            }
        }
        for(int j = 0; j < m; j++)
        {
            if(arr[0][j] != -1)
            {
                if(100 <= arr[0][j] && arr[0][j] <= 125)
                {
                    door_queue.push({door_seq, {0, j}});
                }
                else
                {
                    bfs_queue.push({0, j});
                    visited[0][j] = true;
                }
            }
            if(arr[n - 1][j] != -1)
            {
                if(100 <= arr[n-1][j] && arr[n-1][j] <= 125)
                {
                    door_queue.push({door_seq, {n - 1, j}});
                }
                else
                {
                    bfs_queue.push({n - 1, j});
                    visited[n - 1][j] = true;
                }
            }
        }

        int count = 0;
        int dy[4] = {0, 0, 1, -1};
        int dx[4] = {1, -1, 0, 0};

        if(bfs_queue.empty())
        {
            while(!door_queue.empty() && door_queue.front().first == door_seq)
            {
                int curr_doorseq = door_queue.front().first;
                int curr_y = door_queue.front().second.first;
                int curr_x = door_queue.front().second.second;
                door_queue.pop();

                if(100 <= arr[curr_y][curr_x] && arr[curr_y][curr_x] <= 125)
                {
                    if(keys[arr[curr_y][curr_x] - 100] == true)
                    {
                        arr[curr_y][curr_x] = 0;
                        visited[curr_y][curr_x] = true;
                        bfs_queue.push({curr_y, curr_x});
                    }
                    else
                    {
                        door_queue.push({curr_doorseq+1, {curr_y, curr_x}});
                    }
                }
            }
            door_seq++;
        }

        while(!bfs_queue.empty())
        {
            int curr_y = bfs_queue.front().first;
            int curr_x = bfs_queue.front().second;
            bfs_queue.pop();

            if(arr[curr_y][curr_x] != -1)
            {
                if(200 <= arr[curr_y][curr_x] && arr[curr_y][curr_x] <= 225)
                {
                    keys[arr[curr_y][curr_x] - 200] = true;
                    arr[curr_y][curr_x] = 0;
                }
                else if(arr[curr_y][curr_x] == 1000)
                {
                    arr[curr_y][curr_x] = 0;
                    count++;
                }
            }

            for(int i = 0; i < 4; i++)
            {
                int y = curr_y + dy[i];
                int x = curr_x + dx[i];

                if(y < 0 || y >= n || x < 0 || x >= m)
                {
                    continue;
                }
                if(arr[y][x] == -1 || visited[y][x] == true)
                {
                    continue;
                }
                
                visited[y][x] = true;

                if(100 <= arr[y][x] && arr[y][x] <= 125)
                {
                    door_queue.push({door_seq, {y, x}});
                }
                else
                {
                    bfs_queue.push({y, x});
                }
            }

            if(bfs_queue.empty())
            {
                while(!door_queue.empty() && door_queue.front().first == door_seq)
                {
                    int curr_doorseq = door_queue.front().first;
                    int curr_y = door_queue.front().second.first;
                    int curr_x = door_queue.front().second.second;
                    door_queue.pop();

                    if(100 <= arr[curr_y][curr_x] && arr[curr_y][curr_x] <= 125)
                    {
                        if(keys[arr[curr_y][curr_x] - 100] == true)
                        {
                            arr[curr_y][curr_x] = 0;
                            visited[curr_y][curr_x] = true;
                            bfs_queue.push({curr_y, curr_x});
                        }
                        else
                        {
                            door_queue.push({curr_doorseq+1, {curr_y, curr_x}});
                        }
                    }
                }
                door_seq++;
            }
        }

        cout << count << "\n";
    }
}