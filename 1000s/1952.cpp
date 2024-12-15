#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;

    vector <vector <bool>> arr(m, vector <bool>(n));
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};

    int count = 0;
    int direction = 0;
    int total_count = 0;

    int x = 0, y = 0;
    while(total_count < m*n)
    {
        if(0 <= x && x < n && 0 <= y && y < m && !arr[y][x])
        {
            arr[y][x] = true;
            total_count++;

            int next_y = y + dy[direction];
            int next_x = x + dx[direction];

            if(0 <= next_x && next_x < n && 0 <= next_y && next_y < m && !arr[next_y][next_x])
            {
                y = next_y;
                x = next_x;
            }
            else
            {
                direction = (direction + 1) % 4;
                y += dy[direction];
                x += dx[direction];
                count++;
            }
        }
    }

    count--;
    cout << count;
}