#include <iostream>

using namespace std;

int main()
{
    int width, height, x, y, p, radius;
    cin >> width >> height >> x >> y >> p;
    radius = height / 2;
    
    int count = 0;
    for(int i = 0; i < p; i++)
    {
        int player_x, player_y;
        cin >> player_x >> player_y;

        if(x <= player_x && player_x <= x + width && y <= player_y && player_y <= y+height)
        {
            count++;
        }
        else
        {
            int dist1 = abs(x-player_x) * abs(x-player_x) + abs(y+radius-player_y) * abs(y+radius-player_y);
            int dist2 = abs(x+width-player_x) * abs(x+width-player_x) + abs(y+radius-player_y) * abs(y+radius-player_y);

            if(dist1 <= radius*radius || dist2 <= radius*radius)
            {
                count++;
            }
        }    
    }
    
    cout << count;
}