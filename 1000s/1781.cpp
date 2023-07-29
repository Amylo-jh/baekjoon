#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool comp_vec(pair <int, int> a, pair <int, int> b)
{
    if(a.first < b.first)
    {
        return a.first < b.first;
    }
    else if(a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // deadline, ramen;
    vector <pair <int, int>> tasks(n);
    priority_queue <int, vector<int>, greater<>> completed_ramen;
    for(int i = 0; i < n; i++)
    {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(), tasks.end(), comp_vec);

    int curr_day = 0;
    int ramen = 0;
    for(int i = 0; i < n; i++)
    {
        if(tasks[i].first > curr_day)
        {
            completed_ramen.push(tasks[i].second);
            curr_day++;
        }
        else
        {
            if(tasks[i].second > completed_ramen.top())
            {
                completed_ramen.pop();
                completed_ramen.push(tasks[i].second);
            }
        }
    }

    while(!completed_ramen.empty())
    {
        ramen += completed_ramen.top();
        completed_ramen.pop();
    }

    cout << ramen;
}