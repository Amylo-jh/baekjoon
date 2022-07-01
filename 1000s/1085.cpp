#include <iostream>

using namespace std;

int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int distance[4] = {x, w-x, y, h-y};

    int min_distance = distance[0];

    for(int i = 0; i < 4; i++)
    {
        if(min_distance > distance[i])
        {
            min_distance = distance[i];
        }
    }

    cout << min_distance;
}