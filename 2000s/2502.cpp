#include <iostream>

using namespace std;

int main()
{
    int day, tteok;
    cin >> day >> tteok;

    int a[31] = {0, 1, 0};
    int b[31] = {0, 0, 1};

    for(int i = 3; i < 31; i++)
    {
        a[i] = a[i-1] + a[i-2];
        b[i] = b[i-1] + b[i-2];
    }

    for(int amount = 1; amount*a[day] < tteok; amount++)
    {
        if( ( (tteok - (a[day] * amount)) % b[day]) == 0)
        {
            cout << amount << "\n" << ((tteok - (a[day] * amount)) / b[day]);
            break;
        }
    }
}