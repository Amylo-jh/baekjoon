#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        int l, r, c;
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0)
        {
            break;
        }

        vector <vector <vector <int>>> arr(l, vector <vector <int>> (r, vector <int> (c)));
        vector <vector <vector <bool>>> visited(l, vector <vector <bool>> (r, vector <bool> (c, false)));
        queue <array <int, 4>> bfs_queue;
        for(int i = 0; i < l; i++)
        {
            for(int j = 0; j < r; j++)
            {
                string str;
                cin >> str;
                for(int k = 0; k < c; k++)
                {
                    if(str[k] == '.')
                    {
                        arr[i][j][k] = 0;
                    }
                    else if(str[k] == '#')
                    {
                        arr[i][j][k] = 10;
                    }
                    else if(str[k] == 'S')
                    {
                        arr[i][j][k] = 1;
                        bfs_queue.push({i, j, k, 0});
                        visited[i][j][k] = true;
                    }
                    else if(str[k] == 'E')
                    {
                        arr[i][j][k] = 2;
                    }
                }
            }
        }

        int dz[6] = {0, 0, 0, 0, 1, -1};
        int dy[6] = {0, 0, 1, -1, 0, 0};
        int dx[6] = {1, -1, 0, 0, 0, 0};
        bool flag = false;
        while(!bfs_queue.empty())
        {
            array <int, 4> cur = bfs_queue.front();
            bfs_queue.pop();
            for(int i = 0; i < 6; i++)
            {
                int nz = cur[0] + dz[i];
                int ny = cur[1] + dy[i];
                int nx = cur[2] + dx[i];
                if(0 <= nz && nz < l && 0 <= ny && ny < r && 0 <= nx && nx < c && !visited[nz][ny][nx] && arr[nz][ny][nx] != 10)
                {
                    if(arr[nz][ny][nx] == 2)
                    {
                        cout << "Escaped in " << cur[3] + 1 << " minute(s)." << "\n";
                        flag = true;
                    }
                    bfs_queue.push({nz, ny, nx, cur[3] + 1});
                    visited[nz][ny][nx] = true;
                }
            }
        }

        if(!flag)
        {
            cout << "Trapped!" << "\n";
        }
    }
}