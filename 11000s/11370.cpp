#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
    while(1)
    {
        int w, h;
        cin >> w >> h;
        if(w == 0 && h == 0)
        {
            break;
        }
        vector <vector <int>> arr(h, vector <int> (w, 0));
        vector <vector <bool>> visited(h, vector <bool> (w, false));
        queue <pair <int, int>> bfs_queue;
        int dy[4] = {-1, 0, 1, 0};
        int dx[4] = {0, 1, 0, -1};
        for(int i = 0; i < h; i++)
        {
            string str;
            cin >> str;
            for(int j = 0; j < w; j++)
            {
                if(str[j] == 'T')
                {
                    arr[i][j] = 1;
                }
                else if(str[j] == 'S')
                {
                    arr[i][j] = 2;
                    bfs_queue.push({i, j});

                }
            }
        }
        while(!bfs_queue.empty())
        {
            int cy = bfs_queue.front().first;
            int cx = bfs_queue.front().second;
            bfs_queue.pop();
            for(int i = 0; i < 4; i++)
            {
                int ny = cy+dy[i];
                int nx = cx+dx[i];
                if(0 <= ny && ny < h && 0 <= nx && nx < w && !visited[ny][nx] && arr[ny][nx] == 1)
                {
                    visited[ny][nx] = true;
                    arr[ny][nx] = 2;
                    bfs_queue.push({ny, nx});
                }
            }
        }

        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                if(arr[i][j] == 0)
                {
                    cout << ".";
                }
                else if(arr[i][j] == 1)
                {
                    cout << "T";
                }
                else if(arr[i][j] == 2)
                {
                    cout << "S";
                }
            }
            cout << "\n";
        }
    }
}