#include <iostream>

using namespace std;

int main()
{
    double v, w, d;
    cin >> v >> w >> d;

    int count = 0;

    double time = 0;

    while(d > 0)
    {
        time = w / v;
        d -= 5 * time * time;
        if(d > 0)
        {
            count++;
        }
        w *= 1.25;
    }

    cout << count;
}