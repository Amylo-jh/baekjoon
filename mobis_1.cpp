#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (vector <int> a, vector <int> b)
{
    if(a[0] > b[0])
    {
        return true;
    }
    else if(a[0] == b[0])
    {
        if(a[1] > b[1])
        {
            return true;
        }
        else if(a[1] == b[1])
        {
            if(a[2] > b[2])
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <vector <int>> cars;
    int car;
    cin >> car;

    for(int i = 1; i <= car; i++)
    {
        int speed, health;
        cin >> speed >> health;
        vector car_info = {speed, health, i};
        cars.push_back(car_info); 
    }

    sort(cars.begin(), cars.end(), comp);

    int sum_car = 0;
    int curr_speed = -1;
    for(int i = 0; i < car; i++)
    {
        if(cars[i][0] != curr_speed)
        {
            curr_speed = cars[i][0];
            sum_car += cars[i][2];
        }
    }

    cout << sum_car;
}