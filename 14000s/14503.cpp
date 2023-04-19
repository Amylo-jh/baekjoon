#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <vector <int>> field;
vector <pair<int, int>> direction = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; //북, 서, 남, 동

bool check(int y, int x)
{
    bool result = false;
    for(int i = 0; i < 4; i++)
    {
        int curr_y = y + direction[i].first;
        int curr_x = x + direction[i].second;

        if(0 <= curr_y && curr_y < n && 0 <= curr_x && curr_x < m)
        {
            if(field[curr_y][curr_x] == 0)
            {
                result = true;
            }
        }
    }

    return result;
}

bool check_front(int y, int x, int direction_index)
{
    bool result = false;
    int curr_y = y + direction[direction_index].first;
    int curr_x = x + direction[direction_index].second;

    if(0 <= curr_y && curr_y < n && 0 <= curr_x && curr_x < m)
    {
        if(field[curr_y][curr_x] == 0)
        {
            result = true;
        }
    }

    return result;
}

int rotate(int direction_index)
{
    direction_index = (direction_index + 1) % 4;
    return direction_index;
}

int main()
{
    int y, x, direction_index;
    cin >> n >> m >> y >> x >> direction_index;
    
    switch (direction_index)
    {
    case 0:
        direction_index = 0;
        break;
    case 1:
        direction_index = 3;
        break;
    case 2:
        direction_index = 2;
        break;
    case 3:
        direction_index = 1;
        break;
    default:
        break;
    }

    field.resize(n);
    for(int i = 0; i < n; i++)
    {
        field[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            cin >> field[i][j];            
        }
    }

    int count = 0;
    while(1)
    {
        if(!field[y][x])
        {
            count++;
            field[y][x] = 2;
        }

        if(check(y, x))
        {
            direction_index = rotate(direction_index);
            while (!check_front(y, x, direction_index))
            {
                direction_index = rotate(direction_index);
            }
            
            y += direction[direction_index].first;
            x += direction[direction_index].second;
            continue;
        }
        else
        {
            int test_y = y + direction[(direction_index + 2) % 4].first;
            int test_x = x + direction[(direction_index + 2) % 4].second;

            if(0 <= test_y && test_y < n && 0 <= test_x && test_x < m && field[test_y][test_x] != 1)
            {
                y = test_y;
                x = test_x;
            }   
            else
            {
                break;
            }
        }
    }

    cout << count;
}