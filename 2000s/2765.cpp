#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    while(1)
    {
        count++;
        double diameter, rotation, time;
        cin >> diameter >> rotation >> time;

        if(rotation == 0)
        {
            break;
        }

        double pi = 3.1415927;
        double distance = pi * diameter * rotation / 5280 / 12;
        double mph = distance / time * 3600;

        cout << fixed;
        cout.precision(2);
        cout << "Trip #" << count << ": " << distance << " " << mph << "\n";
    }
}