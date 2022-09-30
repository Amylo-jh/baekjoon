#include <iostream>
#include <string>
#include <set>

using namespace std;

int get_time(string time)
{
    int hour = stoi(time.substr(0,2));
    int min = stoi(time.substr(3,2));
    return hour*60 + min;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //start_time, end_time, end_stream_time;
    int time[3] = {};
    for(int i = 0; i < 3; i++)
    {
        string temp;
        cin >> temp;
        time[i] = get_time(temp);
    }

    set <string> attendance_list;

    int attendance_count = 0;
    while(!cin.eof())
    {
        string time_str;
        int chat_time;
        string name;
        cin >> time_str >> name;
        if(time_str == "")
        {
            break;
        }
        chat_time = get_time(time_str);

        if(chat_time <= time[0])
        {
            attendance_list.insert(name);
        }
        else if(time[1] <= chat_time && chat_time <= time[2])
        {
            if(attendance_list.count(name))
            {
                attendance_list.erase(name);
                attendance_count++;
            }
        }
    }

    cout << attendance_count;
}