#include <iostream>
#include <string>

using namespace std;

int get_year(string str)
{
    str = str.substr(0, 4);
    int year = stoi(str);
    return year;
}

int get_month(string str)
{
    str = str.substr(5, 2);
    int month = stoi(str);
    return month;
}

int get_date(string str)
{
    str = str.substr(8, 2);
    int date = stoi(str);
    return date;
}

int main()
{
    string curr_time;
    cin >> curr_time;

    int year = get_year(curr_time);
    int month = get_month(curr_time);
    int date = get_date(curr_time);
    
    int n;
    cin >> n;

    int counter = 0;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        int curr_year = get_year(str);
        int curr_month = get_month(str);
        int curr_date = get_date(str);

        if(year < curr_year)
        {
            counter++;
            continue;
        }
        else if(year == curr_year)
        {
            if(month < curr_month)
            {
                counter++;
                continue;
            }
            else if(month == curr_month)
            {
                if(date <= curr_date)
                {
                    counter++;
                    continue;;
                }
            }
        }
    }

    cout << counter;
}