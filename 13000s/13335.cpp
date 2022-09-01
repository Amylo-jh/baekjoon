#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int truck;
    int bridge_length;
    int bridge_maxweight;
    cin >> truck >> bridge_length >> bridge_maxweight;
    
    vector <int> trucks(truck);
    queue <int> bridge_status;
    int curr_weight = 0;
    int time = 0;

    for(int i = 0; i < truck; i++)
    {
        cin >> trucks[i];
    }
    for(int i = 0; i < bridge_length; i++)
    {
        bridge_status.push(0);
    }

    int index = 0;
    int out_truck = 0;
    while (index < truck || out_truck < truck)
    {
        int temp = bridge_status.front();
        bridge_status.pop();
        curr_weight -= temp;

        if(curr_weight + trucks[index] <= bridge_maxweight)
        {
            curr_weight += trucks[index];
            bridge_status.push(trucks[index]);
            index++;
            time++;
        }
        else
        {
            bridge_status.push(0);
            time++;
        }

        if(temp != 0)
        {
            out_truck++;
        }
    }
    
    cout << time;
}