#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
    int target;
    cin >> target;

    vector <int> dp(2001);
    dp.assign(2001, INT32_MAX);
    dp[0] = 0;
    dp[1] = 0;

    queue <tuple <int, int, int>> bfs_queue;
    bfs_queue.push(make_tuple(1, 0, 0));

    while(!bfs_queue.empty())
    {
        int num = get<0>(bfs_queue.front());
        int clip = get<1>(bfs_queue.front());
        int time = get<2>(bfs_queue.front());
        bfs_queue.pop();
       
        int next_num = num;
        int next_clip = clip;
        int next_time = time+1;
        
        tuple <int, int, int> next_tuple[3];
        // operation 1
        next_clip = num;
        next_tuple[0] = make_tuple(next_num, next_clip, next_time);

        // operation 2
        next_num = num + clip;
        next_clip = clip;
        next_tuple[1] = make_tuple(next_num, next_clip, next_time);

        // operation 3
        next_num = num - 1;
        if(next_num < 0)
        {
            next_num = 0;
        }
        next_clip = clip;
        next_tuple[2] = make_tuple(next_num, next_clip, next_time);

        for(int i = 0; i < 3; i++)
        {
            next_num = get<0>(next_tuple[i]);
            next_clip = get<1>(next_tuple[i]);
            next_time = get<2>(next_tuple[i]);

            if(next_num > 2000)
            {
                continue;
            }

            if(dp[next_num] >= next_time-1)
            {
                dp[next_num] = min(dp[next_num], next_time);
                bfs_queue.push(next_tuple[i]);
            }
        }
    }

    cout << dp[target];
}