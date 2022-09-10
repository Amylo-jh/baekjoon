#include <iostream>
#include <queue>

using namespace std;

queue <pair <int, int>> bfs_queue;
queue <pair <int, int>> bfs_queue2;

int bfs(int count)
{
    count++;

    while(!bfs_queue.empty())
    {
        pair <int, int> score = bfs_queue.front();
        bfs_queue.pop();

        int a_1 = score.first * 2;
        int b_1 = score.second + 3;

        int a_2 = score.first + 1;
        int b_2 = score.second;

        if(a_1 == b_1 ||
        a_2 == b_2)
        {
            bfs_queue = {};
            bfs_queue2 = {};
            break;
        }
        else
        {
            if(a_1 < b_1)
            {
                bfs_queue2.push({a_1, b_1});    
            }
            if(a_2 < b_2)
            {
                bfs_queue2.push({a_2, b_2});
            }
        }
    }

    if(!bfs_queue2.empty())
    {
        bfs_queue = bfs_queue2;
        bfs_queue2 = {};
        count = bfs(count);
    }
    
    return count;
}


int main()
{
    int tc;
    cin >> tc;
    
    for(int q = 0; q < tc; q++)
    {
        bfs_queue = {};
        bfs_queue2 = {};
        pair <int, int> score;
        cin >> score.first >> score.second;
        bfs_queue.push(score);
        cout << bfs(0) << "\n";
    }
}