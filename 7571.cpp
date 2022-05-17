#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, dots;
    int mid_x = 0;
    int mid_y = 0;

    int total_move = 0;

    vector <int> x;
    vector <int> y;

    cin >> n >> dots;

    for(int i = 0; i < dots; i++)
    {
        int temp_x;
        int temp_y;
        cin >> temp_x >> temp_y;
        x.push_back(temp_x);
        y.push_back(temp_y);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    mid_x = x[dots/2];
    mid_y = y[dots/2];


    for(int i = 0; i < dots; i++)
    {
        int move_x = mid_x - x[i];
        int move_y = mid_y - y[i];

        move_x = abs(move_x);
        move_y = abs(move_y);

        total_move += move_x + move_y;
    }

    cout << total_move;
}