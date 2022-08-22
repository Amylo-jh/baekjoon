#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector <queue <int>> task_dependency(n+1);
    set <int> dependency;
    queue <int> task_queue;

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        task_dependency[b].push(a);
    }

    int target_task;
    cin >> target_task;

    task_queue = task_dependency[target_task];

    while(!task_queue.empty())
    {
        int curr_task = task_queue.front();
        task_queue.pop();
        dependency.insert(curr_task);

        while(!task_dependency[curr_task].empty())
        {
            task_queue.push(task_dependency[curr_task].front());
            task_dependency[curr_task].pop();
        }
    }

    cout << dependency.size();
}