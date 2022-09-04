#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (pair <int, int> a, pair <int, int> b)
{
    return a.second > b.second;
}

int main()
{
    int task;
    cin >> task;

    //running time, deadline
    vector <pair <int, int>> tasks(task);

    for(int i = 0; i < task; i++)
    {
        pair <int, int> temp_pair;
        cin >> temp_pair.first >> temp_pair.second;
        tasks[i] = temp_pair;
    }

    sort(tasks.begin(), tasks.end(), comp);

    int finish_time;
    for(int i = 0; i < task; i++)
    {
        finish_time = tasks[i].second - tasks[i].first;

        if(i+1 != task)
        {
            if(finish_time < tasks[i+1].second)
            {
                tasks[i+1].second = finish_time;
            }    
        }
    }

    if(finish_time < 0)
    {
        cout << -1;
    }
    else
    {
        cout << finish_time;
    }
}