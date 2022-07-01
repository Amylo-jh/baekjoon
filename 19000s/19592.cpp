#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int testcase = 0; testcase < t; testcase++)
    {
        int n, track_length, max_booster;
        cin >> n >> track_length >> max_booster;

        int max_participant_speed = 0;
        for(int i = 0; i < n-1; i++)
        {
            int temp;
            cin >> temp;
            if(temp > max_participant_speed)
            {
                max_participant_speed = temp;
            }
        }
        int my_speed;
        cin >> my_speed;

        if(my_speed > max_participant_speed)
        {
            cout << 0 << endl;
            continue;
        }

        double fastest_participant_laptime;
        fastest_participant_laptime = double(track_length) / double(max_participant_speed);

        double required_cruise_time = fastest_participant_laptime - 1;
        double required_cruise_distance = required_cruise_time * my_speed;

        double required_booster_distance = track_length - required_cruise_distance;
        double required_booster_speed = ceil(required_booster_distance);

        if(required_booster_distance == required_booster_speed)
        {
            required_booster_speed++;
        }

        if(required_booster_speed > max_booster)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << required_booster_speed << endl;
        }
    }
}