#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct location
{
    int x;
    int y;
};

int get_distance (location a, location b)
{
    int distance = abs(a.x - b.x) * abs(a.x - b.x) + abs(a.y - b.y) * abs(a.y - b.y);

    return distance;
}

bool compare (location a, location b)
{
    if(a.x < b.x)
    {
        return true;
    }
    else if(a.x == b.x)
    {
        if(a.y < b.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    return false;
}

int main()
{
    int t;
    cin >> t;

    location locations[4];

    for(int k = 0; k < t; k++)
    {
        for(int i = 0; i < 4; i++)
        {
            cin >> locations[i].x >> locations[i].y;
        }

        sort(locations, locations+4, compare);

        int d1 = get_distance(locations[0], locations[1]);
        int d2 = get_distance(locations[1], locations[3]);
        int d3 = get_distance(locations[3], locations[2]);
        int d4 = get_distance(locations[0], locations[2]);

        int d_d1 = get_distance(locations[0], locations[3]);
        int d_d2 = get_distance(locations[1], locations[2]);

        if(d1 == d2 && d2 == d3 && d3 == d4 && d_d1 == d1 + d2 && d_d2 == d1 + d4)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}