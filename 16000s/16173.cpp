#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    vector <vector <int>> area;
    vector <vector <bool>> visited;
    queue <pair <int, int>> bfs;
    bfs.push({0,0});
    bool flag = false;

    int size;
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        vector <int> temp;
        vector <bool> temp_bool;
        for(int j = 0; j < size; j++)
        {
            int tempint;
            cin >> tempint;
            temp.push_back(tempint);
            temp_bool.push_back(false);
        }
        area.push_back(temp);
        visited.push_back(temp_bool);
    }

    while(bfs.empty() == false)
    {
        int curr_x = bfs.front().first;
        int curr_y = bfs.front().second;

        if(visited[curr_x][curr_y])
        {
            bfs.pop();
            continue;
        }

        if(area[curr_x][curr_y] == -1)
        {
            flag = true;
            break;
        }

        if(area[curr_x][curr_y] != 0)
        {
            int x[2] = {curr_x, curr_x + area[bfs.front().first][bfs.front().second]};
            int y[2] = {curr_y + area[bfs.front().first][bfs.front().second], curr_y};

            for(int i = 0; i < 2; i++)
            {
                if(x[i] < size && y[i] < size)
                {
                    bfs.push({x[i], y[i]});
                }
            }
        }
        
        visited[curr_x][curr_y] = true;
        bfs.pop();
    }

    if(flag)
    {
        cout << "HaruHaru";
    }
    else
    {
        cout << "Hing";
    }
}