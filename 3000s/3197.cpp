#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector <vector <bool>> area;
vector <vector <bool>> swan_visited;
vector <pair <int, int>> swans;
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    area.resize(n);
    swan_visited.resize(n);
    
    queue <pair <int, pair <int, int>>> water_queue;
    queue <pair <int, pair <int, int>>> water_queue2;
    queue <pair <int, pair <int, int>>> swan_queue;
    queue <pair <int, pair <int, int>>> swan_queue2;

    for(int i = 0; i < n; i++)
    {
        area[i].resize(m);
        swan_visited[i].resize(m);
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == 'X')
            {
                area[i][j] = false;
            }
            else if(str[j] == '.')
            {
                area[i][j] = true;
                water_queue.push({0, {i, j}});
            }
            else if(str[j] == 'L')
            {
                area[i][j] = true;
                water_queue.push({0, {i, j}});
                swans.push_back({i, j});
            }
        }
    }
    swan_queue.push({0, swans[0]});
    swan_visited[swans[0].first][swans[0].second] = true;

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    int counter = 0;

    while(1)
    {
        queue <pair <int, int>> next_ice;
        while(!water_queue.empty() )//&& water_queue.front().first == counter)
        {
            int curr_y = water_queue.front().second.first;
            int curr_x = water_queue.front().second.second;
            int day = water_queue.front().first;
            water_queue.pop();

            for(int i = 0; i < 4; i++)
            {
                int y = curr_y + dy[i];
                int x = curr_x + dx[i];
                if(0 <= y && y < n && 0 <= x && x < m)
                {
                    if(area[y][x] == false)
                    {
                        water_queue2.push({day+1, {y, x}});
                        area[y][x] = true;
                    }
                }
            }
        }

        bool is_swan_found = false;
        while(!swan_queue.empty() )// && swan_queue.front().first == counter)
        {
            if(swan_queue.front().second == swans[1])
            {
                is_swan_found = true;
                swan_queue = {};
                break;
            }
            int curr_y = swan_queue.front().second.first;
            int curr_x = swan_queue.front().second.second;
            int day = swan_queue.front().first;
            swan_queue.pop();
            swan_visited[curr_y][curr_x] = true;

            for(int i = 0; i < 4; i++)
            {
                int y = curr_y + dy[i];
                int x = curr_x + dx[i];
                if(0 <= y && y < n && 0 <= x && x < m && !swan_visited[y][x])
                {
                    swan_visited[y][x] = true;
                    if(area[y][x] == true)
                    {
                        swan_queue.push({day, {y, x}});
                    }
                    if( area[y][x] == false)
                    {
                        swan_queue2.push({day+1, {y, x}});
                    } 
                }
            }
        }

        counter++;
        swan_queue = swan_queue2;
        water_queue = water_queue2;
        swan_queue2 = {};
        water_queue2 = {};
        if(is_swan_found)
        {
            break;
        }
    }

    cout << counter;
}