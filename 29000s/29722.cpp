#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int year = stoi(str.substr(0, 4));
    int month = stoi(str.substr(5, 2));
    int day = stoi(str.substr(8, 2));

    int total_day = year*360 + month*30 + day;
    int period;
    cin >> period;
    total_day += period;

    year = total_day / 360;
    total_day %= 360;
    month = total_day / 30;
    total_day %= 30;
    day = total_day;

    if(month == 0)
    {
        year--;
        month = 12;
    }
    if(day == 0)
    {
        month--;
        day = 30;
    }

    cout << year;
    cout << "-";
    if(month < 10)
    {
        cout << "0";
    }
    cout << month;
    cout << "-";
    if(day < 10)
    {
        cout << "0";
    }
    
    cout << day;

}