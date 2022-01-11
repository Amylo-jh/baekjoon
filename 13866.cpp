#include <iostream>

using namespace std;

int main()
{
    int level[4];
    cin >> level[0] >> level[1] >> level[2] >> level[3];
    int teama;
    int teamb;
    int diff = 0;

    diff = abs(level[0] + level[1] - level[2] - level[3]);

    if(diff > abs(level[0] + level[2] - level[1] - level[3]))
    {
        diff = abs(level[0] + level[2] - level[1] - level[3]);
    }
    if (diff > abs(level[0] + level[3] - level[1] - level[2]))
    {
        diff = abs(level[0] + level[3] - level[1] - level[2]);
    }

    cout << diff;
}