#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int c, r;
    cin >> c >> r;

    vector <vector <int>> arr(r, vector <int> (c));
    vector <pair <int, int>> pos(c*r+1);

    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};
    int direction = 0;
    int count = 1;

    int y = 0, x = 0;
    while(count <= c*r)
    {
        arr[y][x] = count;
        pos[count] = {y+1, x+1};

        int ny = y+dy[direction];
        int nx = x+dx[direction];
        if(ny < 0 || ny >= r || nx < 0 || nx >= c || arr[ny][nx] != 0)
        {
            direction = (direction+1)%4;
            ny = y+dy[direction];
            nx = x+dx[direction];
        }

        y = ny;
        x = nx;
        count++;
    }

    int query;
    cin >> query;

    if(query <= c*r)
    {
        cout << pos[query].second << " " << pos[query].first;
    }
    else
    {
        cout << 0;
    }
}