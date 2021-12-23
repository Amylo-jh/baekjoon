#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Conference_time
{
    int start_time;
    int end_time;
};

bool compare (const Conference_time& t1, const Conference_time& t2)
{
    if(t1.end_time == t2.end_time)
    {
        return t1.start_time < t2.start_time;
    }
    else
    {
        return t1.end_time < t2.end_time;
    }

}

int main()
{
    int conference_count;
    vector <Conference_time> time_list;

    cin >> conference_count;
    time_list.resize(conference_count);

    for(int i = 0; i < conference_count; i++)
    {
        cin >> time_list[i].start_time >> time_list[i].end_time;
    }

    sort(time_list.begin(),time_list.end(),compare);

    int curr_end_time = 0;
    int max_conference = 0;
    for(int i = 0; i < conference_count; i++)
    {
        if(curr_end_time <= time_list[i].start_time)
        {
            curr_end_time = time_list[i].end_time;
            max_conference++;
        }
    }

    cout << max_conference;
}