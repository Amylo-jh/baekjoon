#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int>> area;
vector <vector <int>> unions;
vector <vector <bool>> visited;
int n, l, r;

void make_group()
{
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    int group_count = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                unions[i][j] = group_count;

                queue <pair<int, int>> bfs_queue;
                bfs_queue.push({i, j});
                visited[i][j] = true;
                
                while(!bfs_queue.empty())
                {
                    int curr_y = bfs_queue.front().first;
                    int curr_x = bfs_queue.front().second;
                    bfs_queue.pop();

                    for(int k = 0; k < 4; k++)
                    {
                        int y = curr_y + dy[k];
                        int x = curr_x + dx[k];

                        if(0 <= y && y < n && 0 <= x && x < n && !visited[y][x])
                        {
                            if(l <= abs(area[curr_y][curr_x] - area[y][x]) && abs(area[curr_y][curr_x] - area[y][x]) <= r)
                            {
                                visited[y][x] = true;
                                bfs_queue.push({y, x});
                                unions[y][x] = group_count;
                            }
                        }
                    }
                }

                group_count++;
            }
        }
    }
}

bool move_people()
{
    bool is_moved = false;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                bool current_move_required = false;
                queue <pair <int, int>> bfs_queue;
                vector <pair <int, int>> unions_area;
                bfs_queue.push({i, j});
                unions_area.push_back({i, j});
                visited[i][j] = true;

                while(!bfs_queue.empty())
                {
                    int curr_y = bfs_queue.front().first;
                    int curr_x = bfs_queue.front().second;
                    bfs_queue.pop();

                    if(area[curr_y][curr_x] != area[i][j])
                    {
                        is_moved = true;
                        current_move_required = true;
                    }

                    for(int k = 0; k < 4; k++)
                    {
                        int y = curr_y + dy[k];
                        int x = curr_x + dx[k];
                    
                        if(0 <= y && y < n && 0 <= x && x < n && !visited[y][x] && unions[y][x] == unions[curr_y][curr_x])
                        {
                            visited[y][x] = true;
                            bfs_queue.push({y, x});
                            unions_area.push_back({y, x});
                        }
                    }
                }

                if(current_move_required)
                {
                    int total_people = 0;
                    int union_count = 0;
                    int result_people = 0;
                    for(int k = 0; k < unions_area.size(); k++)
                    {
                        int y = unions_area[k].first;
                        int x = unions_area[k].second;
                        total_people += area[y][x];
                        union_count++;
                    }
                    result_people = total_people / union_count;
                    for(int k = 0; k < unions_area.size(); k++)
                    {
                        int y = unions_area[k].first;
                        int x = unions_area[k].second;
                        area[y][x] = result_people;
                    }
                }
            }
        }
    }

    return is_moved;
}

void clear_visited()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> l >> r;

    area.resize(n);
    unions.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        area[i].resize(n);
        unions[i].resize(n);
        visited[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            cin >> area[i][j];
            unions[i][j] = -1;
        }
    }

    int days = 0;
    bool flag = true;
    while(flag)
    {
        make_group();
        clear_visited();
        flag = move_people();
        if(flag)
        {
            days++;
        }
        clear_visited();
    }

    cout << days;
}