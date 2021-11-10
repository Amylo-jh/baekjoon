#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int station_x, station_y;
    int train_x, train_y;
    int delta_x, delta_y;
    int distance;
    int min_distance = INT32_MAX;
    int spot_x, spot_y;

    cin >> station_x >> station_y;
    cin >> train_x >> train_y >> delta_x >> delta_y;

    for(int i =0; i < 300; i++)
    {
        distance = pow((train_x - station_x),2) + pow((train_y - station_y),2);
        if(distance < min_distance)
        {
            spot_x = train_x;
            spot_y = train_y;
            min_distance = distance;
        }
        train_x = train_x + delta_x;
        train_y = train_y + delta_y;
    }
    cout << spot_x << " " << spot_y;
}