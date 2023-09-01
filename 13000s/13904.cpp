#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // due date, score;
    vector <pair <int, int>> tasks(n);
    int max_day = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> tasks[i].first >> tasks[i].second;
        max_day = max(max_day, tasks[i].first);
    }

    sort(tasks.begin(), tasks.end());

    int total_score = 0;
    priority_queue <int, vector<int>, greater<>> pq;
    int pos = 0;
    for(int i = 1; i <= max_day; i++)
    {
        while(tasks[pos].first <= i && pos < tasks.size())
        {
            if(pq.size() < i)
            {
                pq.push(tasks[pos].second);
            }
            else
            {
                if(pq.top() < tasks[pos].second);
                {
                    pq.pop();
                    pq.push(tasks[pos].second);
                }
            }
            pos++;
        }
    }

    while(!pq.empty())
    {
        total_score += pq.top();
        pq.pop();
    }
    cout << total_score;
}