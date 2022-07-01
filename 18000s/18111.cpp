#include <iostream>
#include <vector>

using namespace std;

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
    vector<vector<int>> map;
    int n, m;
    int blocks;

    int lowest = 256;
    int highest = 0;

    int shortest_time = INT32_MAX;
    int surface_height = 256;
    cin >> n >> m >> blocks;

    for(int i = 0; i < n; i++)
    {
        vector <int> tempvec;
        for(int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;

            lowest = min(lowest, temp);
            highest = max(highest, temp);

            tempvec.push_back(temp);
        }
        map.push_back(tempvec);
    }

    for(int q = highest; q >= lowest; q--)
    {
        int curr_time = 0;
        int curr_block = blocks;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int diff = map[i][j] - q;

                if(diff < 0)
                {
                    curr_time = curr_time + diff * -1;
                    curr_block = curr_block + diff;
                }        
                else if(diff > 0)
                {
                    curr_time = curr_time + diff * 2;
                    curr_block = curr_block + diff;
                }
            }
        }

        if(curr_time < shortest_time && curr_block >= 0)
        {
            shortest_time = curr_time;
            surface_height = q;
        }
    }

    cout << shortest_time << " " << surface_height;
}