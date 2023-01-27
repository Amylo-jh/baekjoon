#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <int> pos(100001);
    pos.assign(100001, 999999);
    pos[n] = 0;

    queue <int> bfs_queue;
    bfs_queue.push(n);

    while(!bfs_queue.empty())
    {
        int target = bfs_queue.front();
        bfs_queue.pop();

        if(target == m)
        {
            break;
        }

        if(target + 1 <= 100000)
        {
            if(pos[target+1] > pos[target] + 1)
            {
                pos[target+1] = pos[target] + 1;
                bfs_queue.push(target+1);
            }
        }
        if(target - 1 >= 0)
        {
            if(pos[target-1] > pos[target] + 1)
            {
                pos[target-1] = pos[target] + 1;
                bfs_queue.push(target-1);
            }            
        }
        if(target * 2 <= 100000)
        {
            if(pos[target*2] > pos[target] + 1)
            {
                pos[target*2] = pos[target] + 1;
                bfs_queue.push(target*2);
            }
        }
    }

    cout << pos[m];    
}