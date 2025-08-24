#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        int n, m;
        cin >> m >> n;
        if(n == 0 && m == 0)
        {
            break;
        }

        vector <vector <bool>> arr(n*2-1, vector <bool>(m*2-1, false));
        vector <vector <int>> dist(n*2-1, vector <int>(m*2-1, 1e9));
        dist[0][0] = 1;
        for(int i = 0; i < n*2-1; i++)
        {
            for(int j = 0; j < m*2-1; j++)
            {
                if((i+j) % 2)
                {
                    int temp;
                    cin >> temp;
                    arr[i][j] = temp;
                }
            }
        }

        queue <pair <int, int>> bfs_queue;
        bfs_queue.push({0, 0});
        int dy[4] = {-2, 0, 2, 0};
        int dx[4] = {0, 2, 0, -2};
        while(!bfs_queue.empty())
        {
            int cy = bfs_queue.front().first;
            int cx = bfs_queue.front().second;
            bfs_queue.pop();

            for(int i = 0; i < 4; i++)
            {
                int ny = cy+dy[i];
                int nx = cx+dx[i];
                if(0 <= ny && ny < n*2-1 && 0 <= nx && nx < m*2-1)
                {
                    if(!arr[(cy+ny)/2][(cx+nx)/2])
                    {
                        if(dist[ny][nx] > dist[cy][cx]+1)
                        {
                            dist[ny][nx] = dist[cy][cx]+1;
                            bfs_queue.push({ny, nx});
                        }
                    }
                }
            }
        }

        if(dist[(n-1)*2][(m-1)*2] != 1e9)
        {
            cout << dist[(n-1)*2][(m-1)*2] << "\n";
        }
        else
        {
            cout << "0\n";
        }
    }
}