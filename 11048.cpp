#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> maze;
vector <vector <int>> maze_max;

void get_max_candy(int pos_y, int pos_x, int max_y, int max_x)
{
    if(maze_max[pos_y][pos_x] == -1)
    {
        if(pos_y == max_y -1 && pos_x == max_x -1)
        {
            maze_max[pos_y][pos_x] = maze[pos_y][pos_x];
            return;
        }
        if(pos_y == max_y - 1)
        {
            get_max_candy(pos_y, pos_x + 1, max_y, max_x);
            maze_max[pos_y][pos_x] = maze[pos_y][pos_x] + maze_max[pos_y][pos_x+1];
            return; 
        }
        else if(pos_x == max_x - 1)
        {
            get_max_candy(pos_y + 1, pos_x, max_y, max_x);
            maze_max[pos_y][pos_x] = maze[pos_y][pos_x] + maze_max[pos_y+1][pos_x];
            return;
        }

        get_max_candy(pos_y + 1, pos_x, max_y, max_x);
        get_max_candy(pos_y, pos_x + 1, max_y, max_x);

        if(maze_max[pos_y+1][pos_x] > maze_max[pos_y][pos_x+1])
        {
            maze_max[pos_y][pos_x] = maze[pos_y][pos_x] + maze_max[pos_y+1][pos_x];
        }
        else
        {
            maze_max[pos_y][pos_x] = maze[pos_y][pos_x] + maze_max[pos_y][pos_x+1];
        }
    }

    return;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        vector <int> temp_vec;
        vector <int> temp_vec2;
        for(int j = 0; j < m; j++)
        {
            int temp = -1;
            temp_vec2.push_back(temp);
            cin >> temp;
            temp_vec.push_back(temp);
        }
        maze.push_back(temp_vec);
        maze_max.push_back(temp_vec2);
    }

    get_max_candy(0,0, n, m);

    int max_candy = maze_max[0][0];

    cout << max_candy;    
}