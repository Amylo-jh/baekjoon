#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int>> area;
vector <vector <bool>> visited;

int main()
{
    int n, m;
    cin >> n >> m;
    area.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        area[i].resize(m);
        visited[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            cin >> area[i][j];
        }
    }
    
    int max_counter = 0;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    for(int i1 = 0; i1 < n; i1++)
    {
        for(int j1 = 0; j1 < m; j1++)
        {
            for(int i2 = 0; i2 < n; i2++)
            {
                for(int j2 = 0; j2 < m; j2++)
                {
                    for(int i3 = 0; i3 < n; i3++)
                    {
                        for(int j3 = 0; j3 < m; j3++)
                        {
                            if( ((i1==i2)&&(j1==j2)) || ((i1==i3)&&(j1==j3)) || ((i2==i3)&&(j2==j3)) )
                            {
                                continue;
                            }
                            if(  area[i1][j1] == 2 || area[i2][j2] == 2 || area[i3][j3] == 2  || area[i1][j1] == 1 || area[i2][j2] == 1 || area[i3][j3] == 1)
                            {
                                continue;
                            }
                            vector <vector <int>> t_area = area;
                            t_area[i1][j1] = 1;
                            t_area[i2][j2] = 1;
                            t_area[i3][j3] = 1;

                            queue <pair <int, int>> bfs_queue;
                            for(int i = 0; i < n; i++)
                            {
                                for(int j = 0; j < m; j++)
                                {
                                    if(t_area[i][j] == 2)
                                    {
                                        bfs_queue.push({i, j});
                                    }
                                }
                            }

                            while(!bfs_queue.empty())
                            {
                                int curr_y = bfs_queue.front().first;
                                int curr_x = bfs_queue.front().second;
                                bfs_queue.pop();

                                for(int i = 0; i < 4; i++)
                                {
                                    int y = curr_y + dy[i];
                                    int x = curr_x + dx[i];
                                    if(0 <= y && y < n && 0 <= x && x < m)
                                    {
                                        if(t_area[y][x] == 0)
                                        {
                                            t_area[y][x] = 2;
                                            bfs_queue.push({y, x});
                                        }
                                    }
                                }
                            }

                            int counter = 0;
                            for(int i = 0; i < n; i++)
                            {
                                for(int j = 0; j < m; j++)
                                {
                                    if(t_area[i][j] == 0)
                                    {
                                        counter++;
                                    }
                                }
                            }

                            if(counter > max_counter)
                            {
                                max_counter = counter;
                            }
                            //max_counter = max(max_counter, counter);
                        }
                    }
                }
            }
        }
    }

    cout << max_counter;
}