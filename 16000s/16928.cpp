#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <int> arr(101);
    vector <int> dice(101);
    for(int i = 1; i <= 100; i++)
    {
        arr[i] = i;
        dice[i] = INT32_MAX;
    }
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }
    dice[1] = 0;
    queue <pair <int, int>> dfs_queue;
    dfs_queue.push({1, 0});

    int dx[6] = {1,2,3,4,5,6};
    while(!dfs_queue.empty())
    {
        int pos = dfs_queue.front().first;
        int roll = dfs_queue.front().second;
        dfs_queue.pop();
        for(int i = 0; i < 6; i++)
        {
            int next_pos = arr[pos + dx[i]];
            if(1 <= next_pos && next_pos <= 100 && dice[next_pos] > roll+1)
            {
                dice[next_pos] = roll+1;
                dfs_queue.push({next_pos, roll+1});
            }
        }
    }

    cout << dice[100];
}