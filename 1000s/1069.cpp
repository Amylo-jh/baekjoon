#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x, y, d, t;
    cin >> x >> y >> d >> t;

    double distance = sqrt(x * x + y * y);
    double minTime = distance;

    double RemainingDistance = distance;
    double currTime = 0;
    while(RemainingDistance > 0)
    {
        if(RemainingDistance < d*2)
        {
            minTime = min(minTime, t + t + currTime);
        }

        RemainingDistance -= d;
        currTime += t;
        if(RemainingDistance >= 0)
        {
            minTime = min(minTime, RemainingDistance + currTime);
            
        }
    }

    if(RemainingDistance < 0)
    {
        minTime = min(minTime, -RemainingDistance + currTime);
    }
    
    cout.precision(20);
    cout << minTime;
}