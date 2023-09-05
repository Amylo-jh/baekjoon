#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <priority_queue <int, vector<int>, greater<>>> problems(6);
    vector <int> goals(6);
    for(int i = 1; i <= 5; i++)
    {
        cin >> goals[i];
    }
    for(int i = 0; i < n; i++)
    {
        int difficulty, time;
        cin >> difficulty >> time;
        problems[difficulty].push(time);
    }

    int total_time = 240;
    for(int i = 1; i <=5; i++)
    {
        int curr_time = problems[i].top();
        total_time += curr_time;
        problems[i].pop();
        for(int j = 1; j < goals[i]; j++)
        {
            int diff = problems[i].top() - curr_time;
            total_time += diff;
            total_time += problems[i].top();
            curr_time = problems[i].top();
            problems[i].pop();
        }
    }

    cout << total_time;
}