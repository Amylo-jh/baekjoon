#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    priority_queue <int> tasks;
    priority_queue <int> times;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        tasks.push(temp);
    }

    for(int i = 0; i < m; i++)
    {
        int time;
        cin >> time;
        times.push(time);
    }

    int count = 0;
    while(!tasks.empty() && !times.empty())
    {
        if(tasks.top() <= times.top())
        {
            tasks.pop();
            times.pop();
            count++;
        }
        else
        {
            tasks.pop();
        }
    }

    cout << count;
}