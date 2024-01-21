#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <pair <int, int>> arr(n);
    vector <int> month = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    for(int i = 0; i < n; i++)
    {
        int s_month, s_date, e_month, e_date;
        cin >> s_month >> s_date >> e_month >> e_date;

        if(s_month < 3)
        {
            s_month = 3;
            s_date = 1;
        }
        if(e_month > 11)
        {
            e_month = 12;
            e_date = 1;
        }

        int s_day = month[s_month] + s_date;
        int e_day = month[e_month] + e_date;

        arr[i] = {s_day, e_day};
    }

    sort(arr.begin(), arr.end());

    int curr_s_date = 60;
    int curr_e_date = 60;
    int next_s_date = 60;
    int next_e_date = 60;
    int count = 1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i].first == curr_s_date)
        {
            curr_e_date = arr[i].second;
            next_s_date = arr[i].first;
            next_e_date = arr[i].second;
        }
        else if(arr[i].first <= curr_e_date)
        {
            if(arr[i].second > next_e_date)
            {
                next_s_date = arr[i].first;
                next_e_date = arr[i].second;
            }
        }
        else
        {
            if(arr[i].first > next_e_date)
            {
                break;
            }
            else
            {
                if(arr[i].first == next_s_date)
                {
                    next_e_date = arr[i].second;
                    continue;
                }
                count++;
                curr_s_date = next_s_date;
                curr_e_date = next_e_date;
                next_s_date = arr[i].first;
                next_e_date = arr[i].second;
            }
        }        
    }

    if(curr_e_date < 335)
    {
        count++;
        curr_s_date = next_s_date;
        curr_e_date = next_e_date;
    }

    if(curr_e_date < 335)
    {
        cout << 0;
    }
    else
    {
        cout << count;
    }
}