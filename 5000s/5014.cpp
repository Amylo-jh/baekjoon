#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    vector<int> arr(f + 1, 1e9);
    vector<bool> visited(f + 1);
    queue<pair<int, int>> bfs_queue;
    bfs_queue.push({s, 0});
    arr[s] = 0;
    while (!bfs_queue.empty())
    {
        int curr_level = bfs_queue.front().first;
        int curr_move = bfs_queue.front().second;
        bfs_queue.pop();

        if (curr_level == g)
        {
            break;
        }
        if (curr_level + u <= f)
        {
            if (arr[curr_level + u] > curr_move + 1)
            {
                arr[curr_level + u] = curr_move + 1;
                bfs_queue.push({curr_level + u, curr_move + 1});
            }
        }
        if (curr_level - d > 0)
        {
            if (arr[curr_level - d] > curr_move + 1)
            {
                arr[curr_level - d] = curr_move + 1;
                bfs_queue.push({curr_level - d, curr_move + 1});
            }
        }
    }
    if (arr[g] == 1e9)
    {
        cout << "use the stairs";
    }
    else
    {
        cout << arr[g];
    }
}