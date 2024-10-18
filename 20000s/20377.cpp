#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    vector <vector <int>> arr(16, vector <int> (3));
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    int a, b, c;
    while(cin >> a >> b >> c)
    {
        int min_dist = INT32_MAX;
        int idx = 0;

        for(int i = 0; i < 16; i++)
        {
            int dist = 0;
            dist += (a - arr[i][0]) * (a - arr[i][0]);
            dist += (b - arr[i][1]) * (b - arr[i][1]);
            dist += (c - arr[i][2]) * (c - arr[i][2]);

            if(dist < min_dist)
            {
                min_dist = dist;
                idx = i;
            }
        }

        cout << setw(3) << a << " " << setw(3) << b << " " << setw(3) << c << " maps to " << setw(3) << arr[idx][0] << " " << setw(3) << arr[idx][1] << " " << setw(3) << arr[idx][2] << "\n";
    }
}