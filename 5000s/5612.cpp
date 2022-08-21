#include <iostream>

using namespace std;

int main()
{
    int n;
    int car;
    bool flag = true;
    cin >> n >> car;

    int max_car = car;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        car += a;
        car -= b;

        max_car = max(max_car, car);
        if(car < 0)
        {
            cout << "0";
            flag = false;
            break;
        }
    }

    if(flag)
    {
        cout << max_car;
    }

}