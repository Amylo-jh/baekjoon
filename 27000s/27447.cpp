#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector <int> customer_time(n);
    int max_time = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> customer_time[i];
        max_time = customer_time[i];
    }

    int togi = 0;
    int coffee = 0;
    int time = 0;
    int index = 0;
    bool flag = true;

    while(time <= max_time)
    {
        if(time == customer_time[index - coffee])
        {
            if(coffee > 0)
            {
                coffee--;
            }
            else
            {
                flag = false;
                cout << "fail";
                break;
            }
            time++;
            continue;
        }
        
        if(customer_time[index] - m <= time && time < customer_time[index])
        {
            if(togi == 0)
            {
                togi++;
            }
            else
            {
                togi--;
                coffee++;
                index++;                
            }
        }
        else if(time < customer_time[index] - m)
        {
            togi++;            
        }

        time++;
    }



    if(flag)
    {
        cout << "success";
    }
}