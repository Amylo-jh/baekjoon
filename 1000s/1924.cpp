#include <iostream>

using namespace std;

int main()
{
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int input_month;
    int input_day;
    int total_day = 0;

    cin >> input_month >> input_day;

    for (int i = 0; i < input_month; i++)
    {
        total_day = total_day + month[i];
    }
    total_day = total_day + input_day;

    switch (total_day % 7)
    {
    case 0:
        cout << "SUN";
        break;
    case 1:
        cout << "MON";
        break;
    case 2:
        cout << "TUE";
        break;
    case 3:
        cout << "WED";
        break;
    case 4:
        cout << "THU";
        break;
    case 5:
        cout << "FRI";
        break;
    case 6:
        cout << "SAT";
        break;
    }
}