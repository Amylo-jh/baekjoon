#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

vector <vector <int>> arr(3);
map <string, int> visited;

int make_visit(vector <vector <int>> arr, int move)
{
    string str = "";
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            str += arr[i][j] + '0';
        }
    }

    visited[str] = move;
    return visited[str];
}

int check_visit(vector <vector <int>> arr)
{
    string str = "";
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            str += arr[i][j] + '0';
        }
    }

    return visited[str];
}

int main()
{
    for(int i = 0; i < 3; i++)
    {
        arr[i].resize(3);
        for(int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    queue <vector <vector <int>>> bfs_queue;
    make_visit(arr, 0);
    bfs_queue.push(arr);

    vector <vector <int>> complete_arr = {{1,2,3}, {4,5,6},{7,8,0}};
    while(!bfs_queue.empty())
    {
        vector <vector <int>> curr_arr = bfs_queue.front();
        bfs_queue.pop();
        int curr_y;
        int curr_x;
        int curr_move = check_visit(curr_arr);

        if(curr_arr == complete_arr)
        {
            cout << check_visit(curr_arr);
            return 0;
        }

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(curr_arr[i][j] == 0)
                {
                    curr_y = i;
                    curr_x = j;
                    break;
                }
            }
        }

        for(int i = 0; i < 4; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];

            if(0 <= y && y < 3 && 0 <= x && x < 3)
            {
                int temp = curr_arr[y][x];
                curr_arr[y][x] = curr_arr[curr_y][curr_x];
                curr_arr[curr_y][curr_x] = temp;

                if(!check_visit(curr_arr))
                {
                    bfs_queue.push(curr_arr);
                    make_visit(curr_arr, curr_move + 1);
                }

                curr_arr[curr_y][curr_x] = curr_arr[y][x];
                curr_arr[y][x] = temp;
            }
        }
    }

    cout << -1;
}