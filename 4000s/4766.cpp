#include <iostream>

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;
    double temp;
    cin >> temp;
    double next_temp = 0;
    while(1)
    {
        cin >> next_temp;
        if(next_temp == 999)
        {
            break;
        }
        else
        {
            cout << next_temp - temp << "\n";
            temp = next_temp;
        }

    }
}