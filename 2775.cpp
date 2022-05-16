#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        int floor;
        int room;
        vector <int> lower_floor;
        vector <int> upper_floor;
        
        cin >> floor >> room;

        for(int i = 1; i <= room; i++)
        {
            lower_floor.push_back(i);
            upper_floor.push_back(i);
        }

        for(int i = 0; i < floor; i++)
        {
            for(int j = 0; j < room; j++)
            {
                if(j == 0)
                {
                    upper_floor[0] = 1;
                }
                else
                {
                    upper_floor[j] = lower_floor[j] + upper_floor[j-1];
                }
            }
            lower_floor = upper_floor;
        }

        cout << upper_floor[room-1] << endl;
    }
}