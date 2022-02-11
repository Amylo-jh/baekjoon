#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct location
{
    int x;
    int y;
};

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

        if( (locations[0].x == locations[1].x) && (locations[2].x == locations[3].x) )
        {}
        else
        {
            cout << "0" << endl;
            continue;
        }

        if( (locations[0].y == locations[2].y) && (locations[1].y == locations[3].y) )
        {}
        else
        {
            cout << "0" << endl;
            continue; 
        }

        if( abs(locations[1].y - locations[0].y) == abs(locations[2].x - locations[0].x) && abs(locations[3].y - locations[2].y) == abs(locations[3].x - locations[1].x) && abs(locations[]))
        {}
        else
        {
            cout << "0" << endl;
            continue; 
        }

        cout << "1" << endl;
    }
}