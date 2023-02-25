#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector <vector <int>> fishbowl;
vector <vector <bool>> visited;
pair <int, int> shark_location;

int n;
int shark_size = 2;
int shark_eat_count = 0;
int time = 0;

bool comp(pair <int, pair<int , int>> a, pair <int, pair<int, int>> b)
{
    if(a.first == b.first)
    {
        if(a.second.first == b.second.first)
        {
            return a.second.second < b.second.second;
        }
        else
        {
            return a.second.first < b.second.first;
        }
    }

    return a.first < b.first;
}

int bfs(pair <int, int> shark_loc, int shark_size)
{
    //distance, location_y, location_x;
    queue <pair <int, pair <int, int>> > bfs_queue;

    //distance, location_y, location_x;
    vector <pair <int, pair <int , int>> > eatable_fish;
    bfs_queue.push(make_pair(0, shark_loc));
    visited[shark_loc.first][shark_loc.second] = true;

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    while(!bfs_queue.empty())
    {
        int curr_y = bfs_queue.front().second.first;
        int curr_x = bfs_queue.front().second.second;
        int curr_dist = bfs_queue.front().first;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];
            if(0 <= y && y < n && 0 <= x && x < n && !visited[y][x] && fishbowl[y][x] <= shark_size)
            {
                visited[y][x] = true;
                if(0 < fishbowl[y][x] && fishbowl[y][x] < shark_size)
                {
                    eatable_fish.push_back({curr_dist + 1, {y, x}});
                }
                else
                {
                    bfs_queue.push({curr_dist + 1, {y, x}});
                }
            }
        }
    }

    int add_time = 0;
    if(eatable_fish.empty())
    {
        add_time = 0;
        return add_time;
    }

    sort(eatable_fish.begin(), eatable_fish.end(), comp);

    add_time = eatable_fish[0].first;
    int edit_y = eatable_fish[0].second.first;
    int edit_x = eatable_fish[0].second.second;
    
    shark_location.first = edit_y;
    shark_location.second = edit_x;
    fishbowl[edit_y][edit_x] = 0;
    shark_eat_count++;

    return add_time;
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
    cin >> n;
    fishbowl.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        fishbowl[i].resize(n);
        visited[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            cin >> fishbowl[i][j];
            if(fishbowl[i][j] == 9)
            {
                shark_location.first = i;
                shark_location.second = j;
                fishbowl[i][j] = 0;
            }
        }
    }

    while(1)
    {
        int add_time = bfs(shark_location, shark_size);
        if(add_time == 0)
        {
            break;
        }
        else
        {
            time += add_time;
            clear_visited();

            if(shark_eat_count == shark_size)
            {
                shark_size++;
                shark_eat_count = 0;
            }
        }
    }

    cout << time;
}