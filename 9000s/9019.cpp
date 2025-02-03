#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int a, b;
        cin >> a >> b;
        vector <pair <int, char>> arr(10001, {INT32_MAX, ' '});
        vector <int> history(10001, -1);
        queue <pair <int, int>> bfs_queue;

        bfs_queue.push({a, 0});
        arr[a] = {0, ' '};
        history[a] = -1;

        while(!bfs_queue.empty())
        {
            int curr = bfs_queue.front().first;
            int count = bfs_queue.front().second;
            bfs_queue.pop();

            if(curr == b)
            {
                break;
            }

            int next = (curr * 2) % 10000;
            if(arr[next].first > count + 1)
            {
                arr[next] = {count+1, 'D'};
                history[next] = curr;
                bfs_queue.push({next, count+1});
            }
            
            next = ((curr+10000)-1) % 10000;
            if(arr[next].first > count + 1)
            {
                arr[next] = {count+1, 'S'};
                history[next] = curr;
                bfs_queue.push({next, count+1});
            }

            next = curr % 1000 * 10 + curr / 1000;
            if(arr[next].first > count + 1)
            {
                arr[next] = {count+1, 'L'};
                history[next] = curr;
                bfs_queue.push({next, count+1});
            }

            next = curr % 10 * 1000 + curr / 10;
            if(arr[next].first > count + 1)
            {
                arr[next] = {count+1, 'R'};
                history[next] = curr;
                bfs_queue.push({next, count+1});
            }
        }

        string result = "";
        while(b != a)
        {
            result += arr[b].second;
            b = history[b];
        }

        reverse(result.begin(), result.end());
        cout << result << '\n';
    }
}