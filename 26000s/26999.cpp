#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;

    vector <vector <bool>> area(n, vector <bool> (m, false));
    vector <vector <bool>> visited(n, vector <bool> (m, false));
    queue <pair <int, int>> q;

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == '*')
            {
                area[i][j] = true;
            }
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int max_area = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(area[i][j] && !visited[i][j])
            {
                int area_size = 0;
                q.push({i, j});
                visited[i][j] = true;
                while(!q.empty())
                {
                    int curr_y = q.front().first;
                    int curr_x = q.front().second;
                    q.pop();
                    area_size++;

                    for(int k = 0; k < 4; k++)
                    {
                        int next_y = curr_y + dy[k];
                        int next_x = curr_x + dx[k];
                        if(next_y >= 0 && next_y < n && next_x >= 0 && next_x < m)
                        {
                            if(area[next_y][next_x] && !visited[next_y][next_x])
                            {
                                q.push({next_y, next_x});
                                visited[next_y][next_x] = true;
                            }
                        }
                    }
                }

                max_area = max(max_area, area_size);
            }
        }
    }

    cout << max_area;
}