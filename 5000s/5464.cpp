#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int parking_lot_size;
    int cars;
    int income = 0;

    cin >> parking_lot_size >> cars;

    vector <int> parking_lot_price(parking_lot_size);
    vector <int> cars_weight(cars);
    vector <int> car_location(cars);
    priority_queue <int, vector<int>, greater<int>> available_parking_lot;
    queue <int> waiting_car;
    
    for(int i = 0; i < parking_lot_size; i++)
    {
        cin >> parking_lot_price[i];
        available_parking_lot.push(i);
    }
    for(int i = 0; i < cars; i++)
    {
        cin >> cars_weight[i];
        car_location[i] = -1;
    }

    for(int i = 0; i < cars*2; i++)
    {
        int car;
        cin >> car;
        
        if(car >= 0)
        {
            car--;
            waiting_car.push(car);
        }
        else
        {
            car *= -1;
            car--;
            
            while (!waiting_car.empty() && !available_parking_lot.empty())
            {
                int curr_car = waiting_car.front();
                int assigned_parking_lot = available_parking_lot.top();
                waiting_car.pop();
                available_parking_lot.pop();

                car_location[curr_car] = assigned_parking_lot;
                income += parking_lot_price[assigned_parking_lot] * cars_weight[curr_car];
            }

            int free_parking_lot = car_location[car];
            available_parking_lot.push(free_parking_lot);            
        }
    }

    cout << income;
}