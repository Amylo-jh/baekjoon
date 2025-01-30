#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        string time;
        int calltime;
        cin >> time >> calltime;
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3, 2));
        int total_time = hour * 60 + minute;

        while(calltime--)
        {
            if(420 <= total_time && total_time < 60*19)
            {
                sum += 10;
            }
            else
            {
                sum += 5;
            }
            total_time++;
        }
    }

    cout << sum;
}