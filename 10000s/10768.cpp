#include <iostream>

using namespace std;
int main()
{
    int month;
    int day;

    cin >> month >> day;

    day += (month-1) * 31;

    if(day == 49)
    {
        cout << "Special";
    }
    else if (day > 49)
    {
        cout << "After";
    }
    else
    {
        cout << "Before";
    }
}