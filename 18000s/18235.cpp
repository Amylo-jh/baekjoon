#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    vector <int> arr(n+1, 0);
    queue <pair <int, int>> bfs_queue;
    bfs_queue.push({a, 1});
    bfs_queue.push({b, 1});

    int jump_distance = 1;
    int day = -1;

    while(!bfs_queue.empty())
    {
        int curr_pos = bfs_queue.front().first;
        int curr_day = bfs_queue.front().second;
        bfs_queue.pop();

        int next_pos = curr_pos + pow(2, curr_day-1);
        if(next_pos <= n)
        {
            if(arr[next_pos] == curr_day)
            {
                day = curr_day;
                break;
            }
            else
            {
                arr[next_pos] = curr_day;
                bfs_queue.push({next_pos, curr_day+1});
            }
        }

        next_pos = curr_pos - pow(2, curr_day-1);
        if(next_pos > 0)
        {
            if(arr[next_pos] == curr_day)
            {
                day = curr_day;
                break;
            }
            else
            {
                arr[next_pos] = curr_day;
                bfs_queue.push({next_pos, curr_day+1});
            }
        }
    }

    cout << day;
}