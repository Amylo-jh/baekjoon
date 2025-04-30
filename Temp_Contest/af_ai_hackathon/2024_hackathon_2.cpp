#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int direction = 1;
int max_balloon = 0;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int change_direction(int curr_direction, int mirror)
{
    if(mirror == 4)
    {
        if(curr_direction == 0)
        {
            return 3;
        }
        else if(curr_direction == 1)
        {
            return 2;
        }
        else if(curr_direction == 2)
        {
            return 1;
        }
        else if(curr_direction == 3)
        {
            return 0;
        }
    }
    else if(mirror == 5)
    {
        if(curr_direction == 0)
        {
            return 1;
        }
        else if(curr_direction == 1)
        {
            return 0;
        }
        else if(curr_direction == 2)
        {
            return 3;
        }
        else if(curr_direction == 3)
        {
            return 2;
        }
    }

    return 0;
}

int main()
{
    cin >> n >> m;

    // 0 : 벽, 1 : 풍선, 2 : 거울, 3 : 빈칸, // 4 = /, 5 = \      /
    vector <vector <int>> grid(n);
    for(int i = 0; i < n; i++)
    {
        grid[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    queue <vector <vector <int>> > q_grid;
    queue <pair <int, int>> q_lazer;
    queue <int> q_direction;
    queue <int> q_balloon;

    q_grid.push(grid);
    q_lazer.push({0, 0});
    q_direction.push(direction);
    q_balloon.push(0);

    while(!q_grid.empty())
    {
        vector <vector <int>> curr_grid = q_grid.front();
        int y = q_lazer.front().first;
        int x = q_lazer.front().second;
        int curr_direction = q_direction.front();
        int curr_balloon = q_balloon.front();
        bool is_dead = false;

        q_grid.pop();
        q_lazer.pop();
        q_direction.pop();
        q_balloon.pop();

        
        // 사전에 영역 내인지 한번 체크
        if(!(0 <= y && y < n && 0 <= x && x < m))
        {
            is_dead = true;
            continue;
        }

        // 영역 안에서 빈 칸 또는 풍선일 경우 현재 방향으로 직진
        while(curr_grid[y][x] == 1 || curr_grid[y][x] == 3)
        {
            if(curr_grid[y][x] == 1)
            {
                curr_grid[y][x] = 3;
                curr_balloon++;
            }

            y += dy[curr_direction];
            x += dx[curr_direction];

            // 움직였는데 범위 밖일 경우
            if(!(0 <= y && y < n && 0 <= x && x < m))
            {
                is_dead = true;
                break;
            }
        }

        // 레이저가 아직 안 죽었고 레이저가 벽을 만났을 경우
        if(!is_dead && curr_grid[y][x] == 0)
        {
            is_dead = true;
        }

        // 레이저가 죽었으면 풍선 상태 반영 후 현재 큐 중료
        if(is_dead)
        {
            max_balloon = max(max_balloon, curr_balloon);
            continue;
        }

        // 거울 만났을 경우 방향 전환 후 큐에 상태 저장
        if(curr_grid[y][x] == 2 || curr_grid[y][x] == 4 || curr_grid[y][x] == 5)
        {
            int next_direction;
            if(curr_grid[y][x] == 2)
            {
                curr_grid[y][x] = 4;
                next_direction = change_direction(curr_direction, 4);
                q_grid.push(curr_grid);
                q_lazer.push({y+dy[next_direction], x+dx[next_direction]});
                q_direction.push(next_direction);
                q_balloon.push(curr_balloon);

                curr_grid[y][x] = 5;
                next_direction = change_direction(curr_direction, 5);
                q_grid.push(curr_grid);
                q_lazer.push({y+dy[next_direction], x+dx[next_direction]});
                q_direction.push(next_direction);
                q_balloon.push(curr_balloon);
            }
            else if(curr_grid[y][x] == 4)
            {
                next_direction = change_direction(curr_direction, 4);
                q_grid.push(curr_grid);
                q_lazer.push({y+dy[next_direction], x+dx[next_direction]});
                q_direction.push(next_direction);
                q_balloon.push(curr_balloon);
            }
            else if(curr_grid[y][x] == 5)
            {
                next_direction = change_direction(curr_direction, 5);
                q_grid.push(curr_grid);
                q_lazer.push({y+dy[next_direction], x+dx[next_direction]});
                q_direction.push(next_direction);
                q_balloon.push(curr_balloon);
            }
        }
    }

    cout << max_balloon;
}