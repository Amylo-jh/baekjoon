#include <iostream>
#include <vector>
#include <string>

using namespace std;

void rot(int d, int& dx, int& dy)
{
    int dyy[4] = {-1, 0, 1, 0};
    int dxx[4] = {0, 1, 0, -1};

    int curr_idx = -1;
    for(int i = 0; i < 4; i++)
    {
        if(dx == dxx[i] && dy == dyy[i])
        {
            curr_idx = i;
            break;
        }
    }

    if(d == -1)
    {
        dx = dxx[(curr_idx+4-1) % 4];
        dy = dyy[(curr_idx+4-1) % 4];
    }
    else if(d == 1)
    {
        dx = dxx[(curr_idx+1) % 4];
        dy = dyy[(curr_idx+1) % 4];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        string command;
        cin >> command;

        int x = 0, y = 0, dx = 0, dy = -1;
        int max_x = 0, max_y = 0, min_x = 0, min_y = 0;

        for(int i = 0; i < command.length(); i++)
        {
            if(command[i] == 'F')
            {
                x += dx;
                y += dy;
            }
            else if(command[i] == 'B')
            {
                x -= dx;
                y -= dy;
            }
            else if(command[i] == 'L')
            {
                rot(-1, dx, dy);
            }
            else if(command[i] == 'R')
            {
                rot(1, dx, dy);
            }
            max_x = max(max_x, x);
            max_y = max(max_y, y);
            min_x = min(min_x, x);
            min_y = min(min_y, y);
        }
        cout << (max_x - min_x) * (max_y - min_y) << "\n";
    }
}