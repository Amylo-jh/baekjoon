#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool comp (pair <string, double> a, pair <string, double> b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        vector <pair <string, double>> time_info(5);

        for(int i = 0; i < 5; i++)
        {
            string temp_str;
            cin >> temp_str;

            double min = stoi(temp_str.substr(3, 2)) * 6;
            double hour = (stoi(temp_str.substr(0, 2))%12) * 30 + min/6/60 * 30;
            double angle = hour - min;
            if(angle < 0)
            {
                angle *= -1;
            }
            if(angle > 180)
            {
                angle = 360 - angle;
            }
            time_info[i].first = temp_str;
            time_info[i].second = angle;
        }

        sort(time_info.begin(), time_info.end(), comp);
        cout << time_info[2].first << "\n";
    }
}