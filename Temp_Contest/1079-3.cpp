#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int l, n, k;
string ink, command;
vector <vector <char>> area;
vector <vector <char>> color;
pair <int, int> pos;

void moveit(pair <int, int> delta)
{
    int n_y = pos.first + delta.first;
    int n_x = pos.second + delta.second;

    if(0 <= n_y && n_y < n && 0 <= n_x && n_x < n)
    {
        if(area[n_y][n_x] != '#')
        {
            pos.first = n_y;
            pos.second = n_x;
        }
    }
}

void jump(int ink_amount, int ink_count)
{
    char curr_ink = ink[ink_count % ink.length()];

    for(int i = -ink_amount; i <= ink_amount; i++)
    {
        for(int j = -ink_amount; j <= ink_amount; j++)
        {
            if(abs(i) + abs(j) <= ink_amount)
            {
                int curr_y = pos.first + i;
                int curr_x = pos.second + j;
                if(0 <= curr_y && curr_y < n && 0 <= curr_x && curr_x < n)
                {
                    if(area[curr_y][curr_x] == '#')
                    {
                        color[curr_y][curr_x] = curr_ink;
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> l >> n >> k;
    cin >> ink;

    area.resize(n);
    color.resize(n);
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        area[i].resize(n);
        color[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            area[i][j] = str[j];
            color[i][j] = str[j];
            if(area[i][j] == '@')
            {
                pos = {i, j};
            }
        }
    }

    cin >> command;

    int ink_amount = 0;
    int ink_count = 0;

    // U, D, L, R, {y,x}
    vector <pair <int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i = 0; i < command.length(); i++)
    {
        if(command[i] == 'j')
        {
            ink_amount++;
        }
        else if(command[i] == 'J')
        {
            jump(ink_amount, ink_count);
            ink_amount = 0;
            ink_count++;
        }
        else if(command[i] == 'U')
        {
            moveit(d[0]);
        }
        else if(command[i] == 'D')
        {
            moveit(d[1]);
        }
        else if(command[i] == 'L')
        {
            moveit(d[2]);
        }
        else if(command[i] == 'R')
        {
            moveit(d[3]);
        }
    }

    // 후처리
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(color[i][j] == '@')
            {
                color[i][j] = '.';
            }
        }
    }
    color[pos.first][pos.second] = '@';

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << color[i][j];
        }
        cout << "\n";
    }

}