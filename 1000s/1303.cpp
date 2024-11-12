#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;

    vector <vector <int>> arr(n, vector <int> (m));
    vector <vector <bool>> visited(n, vector <bool> (m, false));
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == 'W')
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }

    int blue = 0, white = 0;

    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j])
            {
                int size = 0;
                int color = arr[i][j];
                queue <pair <int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                size++;

                while(!q.empty())
                {
                    int curr_y = q.front().first;
                    int curr_x = q.front().second;
                    q.pop();

                    for(int i = 0; i < 4; i++)
                    {
                        int next_y = curr_y + dy[i];
                        int next_x = curr_x + dx[i];

                        if(next_y >= 0 && next_y < n && next_x >= 0 && next_x < m)
                        {
                            if(!visited[next_y][next_x] && arr[next_y][next_x] == color)
                            {
                                q.push({next_y, next_x});
                                visited[next_y][next_x] = true;
                                size++;
                            }
                        }
                    }
                }

                if(color == 1)
                {
                    white += size * size;
                }
                else
                {
                    blue += size * size;
                }
            }
        }
    }

    cout << white << " " << blue;    
}