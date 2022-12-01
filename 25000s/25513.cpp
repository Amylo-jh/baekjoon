#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int>> field(5);
vector <vector <bool>> visited(5);
int pos_y, pos_x;

int bfs(int next_number)
{
    queue <pair <int, int>> bfs_queue;
    queue <pair <int, int>> bfs_queue2;
    bfs_queue.push({pos_y, pos_x});
    visited[pos_y][pos_x] = true;

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    int counter = 1;
    bool flag = false;
    while(!bfs_queue.empty() && !flag)
    {
        int curr_y = bfs_queue.front().first;
        int curr_x = bfs_queue.front().second;
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];

            if(0 <= y && y < 5 && 0 <= x && x < 5 &&
            !visited[y][x])
            {
                visited[y][x] = true;

                if(field[y][x] == next_number)
                {
                    flag = true;
                    pos_y = y;
                    pos_x = x;
                }
                else if(field[y][x] != -1)
                {
                    bfs_queue2.push({y, x});
                }
            }
        }

        if(bfs_queue.empty() && !flag)
        {
            bfs_queue = bfs_queue2;
            bfs_queue2 = {};
            counter++;
        }
    }

    if(!flag)
    {
        counter = -1;
    }

    return counter;
}

void reset_visited()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            visited[i][j] = false;
        }
    }
}

int main()
{
    for(int i = 0; i < 5; i++)
    {
        field[i].resize(5);
        visited[i].resize(5);
        for(int j = 0; j < 5; j++)
        {
            cin >> field[i][j];
        }
    }

    cin >> pos_y >> pos_x;

    int move = 0;
    for(int next_number = 1; next_number <= 6; next_number++)
    {
        reset_visited();
        int curr_move = bfs(next_number);

        if(curr_move == -1)
        {
            move = -1;
            break;
        }
        else
        {
            move += curr_move;
        }
    }

    cout << move;
}