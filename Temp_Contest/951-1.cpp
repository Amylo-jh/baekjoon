#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> score = {10, 8, 6, 5, 4, 3, 2, 1, 0};
    
    vector <pair <int, string> > racer_time(8);
    for(int i = 0; i < 8; i++)
    {
        string time, team;
        cin >> time >> team;

        int min = stoi(time.substr(0, 1));
        int sec = stoi(time.substr(2, 2));
        int ms = stoi(time.substr(5, 3));

        racer_time[i].first = min*60*1000 + sec*1000 + ms;
        racer_time[i].second = team;
    }

    sort(racer_time.begin(), racer_time.end());

    int Red_score = 0;
    int Blu_score = 0;

    for(int i = 0; i < 8; i++)
    {
        if(racer_time[i].second == "B")
        {
            Blu_score += score[i];
        }
        else
        {
            Red_score += score[i];
        }
    }

    if(Blu_score < Red_score)
    {
        cout << "Red";
    }
    else
    {
        cout << "Blue";
    }
}