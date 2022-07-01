#include <iostream>

using namespace std;

int main()
{
    int x, y;
    int ant_x, ant_y;
    int time;

    cin >> x >> y;
    cin >> ant_x >> ant_y;
    cin >> time;

    ant_x = ant_x + time;
    ant_y = ant_y + time;

    ant_x = ant_x % (x*2);
    ant_y = ant_y % (y*2);

    if( (ant_x - x) > 0)
    {
        ant_x = 2*x - ant_x;
    }

    if( (ant_y - y) > 0)
    {
        ant_y = 2*y - ant_y;
    }

    cout << ant_x << " " << ant_y;
}