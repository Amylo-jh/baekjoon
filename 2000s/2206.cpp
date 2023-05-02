#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n, m;
vector <vector <bool>> area;
vector <vector <vector <bool>>> visited;

int bfs()
{
    //y, x, block_count, distance;
    queue <pair <pair <int, int>, pair <int, int> >> bfs_queue;
    bfs_queue.push({{0,0}, {0, 1}});
    visited[0][0][0] = true;
    visited[0][0][1] = true;


    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    bool flag = false;
    int final_distance = INT32_MAX;

    while(!bfs_queue.empty())
    {
        int curr_y = bfs_queue.front().first.first;
        int curr_x = bfs_queue.front().first.second;
        int curr_block = bfs_queue.front().second.first;
        int curr_dist = bfs_queue.front().second.second;
        bfs_queue.pop();
        
        if(curr_y == n-1 && curr_x == m-1)
        {
            final_distance = min(final_distance, curr_dist);
            flag = true;
        }

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];
            
            if(0 <= y && y < n && 0 <= x && x < m)
            {
                if(curr_block == 1)
                {
                    if(!area[y][x] && !visited[y][x][1])
                    {
                        bfs_queue.push({{y, x},{curr_block, curr_dist+1}});
                        visited[y][x][1] = true;
                    }
                }
                else if(!visited[y][x][0])
                {
                    if(area[y][x])
                    {
                        bfs_queue.push({{y,x},{1, curr_dist+1}});
                    }
                    else
                    {
                        bfs_queue.push({{y,x},{0, curr_dist+1}});
                    }
                    visited[y][x][0] = true;
                }
            }
        }
    }

    if(flag)
    {
        return final_distance;
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    area.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        area[i].resize(m);
        visited[i].resize(m);
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            visited[i][j].resize(2);
            if(str[j] == '1')
            {
                area[i][j] = true;
            }
        }
    }

    int final_distance = bfs();
    cout << final_distance;
}