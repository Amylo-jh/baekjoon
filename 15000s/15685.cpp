#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int max_size = 101;
vector <vector <bool>> map(max_size);

void make_dragon(int x, int y, int d, int g)
{
    int dy[4] = {0, -1, 0, 1};
    int dx[4] = {1, 0, -1, 0};
    stack <int> stk;
    stack <int> stk2;
    stk.push(d);
    stk2.push(d);
    
    for(int i = 0; i < g; i++)
    {
        stk2 = stk;
        while(!stk.empty())
        {
            int direction = stk.top();
            stk.pop();
            direction = (direction + 1) % 4;
            stk2.push(direction);
        }
        stk = stk2;
    }
    stk = {};
    while(!stk2.empty())
    {
        stk.push(stk2.top());
        stk2.pop();
    }

    int curr_y = y;
    int curr_x = x;
    map[curr_y][curr_x] = true;
    while(!stk.empty())
    {
        int curr_direction = stk.top();
        stk.pop();
        curr_x += dx[curr_direction];
        curr_y += dy[curr_direction];

        map[curr_y][curr_x] = true;
    }
}

int main()
{
    for(int i = 0; i < max_size; i++)
    {
        map[i].resize(max_size);
    }

    int n;
    cin >> n;
    int x, y, d, g;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> d >> g;
        make_dragon(x, y, d, g);
    }

    int counter = 0;
    for(int i = 0; i < max_size-1; i++)
    {
        for(int j = 0; j < max_size-1; j++)
        {
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1])
            {
                counter++;
            }
        }
    }

    cout << counter;
}