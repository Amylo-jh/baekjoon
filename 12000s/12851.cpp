#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// min_time, path
vector <pair <int, int>> arr(100001);

void bfs(int n, int t)
{
    queue <pair <int, int>> bfs_queue;
    vector <bool> visited(100001);

    bfs_queue.push({n, t});

    while(!bfs_queue.empty())
    {
        int location = bfs_queue.front().first;
        int time = bfs_queue.front().second;
        bfs_queue.pop();

        if(0 <= location && location <= 100000 && !visited[location])
        {
            if(arr[location].first == time)
            {
                arr[location].second++;
            }
            else if(arr[location].first > time)
            {
                arr[location].first = time;
                arr[location].second = 1;
            }
            else
            {
                continue;
            }

            bfs_queue.push({location-1, time+1});
            bfs_queue.push({location+1, time+1});
            bfs_queue.push({location*2, time+1});
        }
    }
}


int main()
{
    int n, k;
    cin >> n >> k;
    arr.assign(100001, {999999,1});

    arr[n] = {0, 0};
    bfs(n, 0);

    cout << arr[k].first << "\n" << arr[k].second;
}