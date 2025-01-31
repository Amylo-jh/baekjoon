#include <iostream>
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
        int n;
        cin >> n;

        vector <vector <int>> board(n, vector <int> (n, INT32_MAX));
        vector <vector <bool>> visited(n, vector <bool> (n, false));
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        board[sx][sy] = 0;
        visited[sx][sy] = true;
        queue <pair <int, int>> bfs_queue;
        bfs_queue.push({sx, sy});

        while(!bfs_queue.empty())
        {
            int x = bfs_queue.front().first;
            int y = bfs_queue.front().second;
            bfs_queue.pop();

            if(x == ex && y == ey)
            {
                cout << board[x][y] << '\n';
                break;
            }

            vector <pair <int, int>> next = {
                {x - 2, y - 1},
                {x - 2, y + 1},
                {x - 1, y - 2},
                {x - 1, y + 2},
                {x + 1, y - 2},
                {x + 1, y + 2},
                {x + 2, y - 1},
                {x + 2, y + 1}
            };

            for(auto &p : next)
            {
                int nx = p.first;
                int ny = p.second;

                if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                {
                    continue;
                }

                if(visited[nx][ny])
                {
                    continue;
                }

                visited[nx][ny] = true;
                board[nx][ny] = board[x][y] + 1;
                bfs_queue.push({nx, ny});
            }
        }
    }
}