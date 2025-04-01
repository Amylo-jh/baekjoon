#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map <string, int> solved_time;
    map <string, int> penalty_time;
    int time;
    string problem, status;

    int solves = 0;
    int penalty = 0;
    while(1)
    {
        cin >> time;
        if(time == -1)
        {
            break;
        }
        cin >> problem >> status;

        if(status == "right")
        {
            if(solved_time[problem] == 0)
            {
                solved_time[problem] = time;
                solves++;
                penalty += time + penalty_time[problem];
            }
        }
        else if(status == "wrong")
        {
            if(solved_time[problem] == 0)
            {
                penalty_time[problem] += 20;
            }
        }
    }

    cout << solves << " " << penalty;
}