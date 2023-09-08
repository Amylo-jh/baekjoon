#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

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
        int turn;
        cin >> turn;
    
        queue <pair <int, int>> bfs_queue;
        // seq, num
        bfs_queue.push({0, 1});

        for(int i = 0; i < turn; i++)
        {
            vector <string> op(2);
            vector <int> v(2);
            cin >> op[0] >> v[0] >> op[1] >> v[1];

            while(!bfs_queue.empty() && bfs_queue.front().first == i)
            {
                int curr_num = bfs_queue.front().second;
                int curr_seq = bfs_queue.front().first;
                bfs_queue.pop();
                for(int q = 0; q < 2; q++)
                {
                    if(op[q] == "+")
                    {
                        bfs_queue.push({i+1, curr_num+v[q]});
                    }
                    else
                    {
                        bfs_queue.push({i+1, curr_num*v[q]});
                    }
                }
            }
        }

        bool flag = false;
        while(!bfs_queue.empty())
        {
            int curr_num = bfs_queue.front().second;
            bfs_queue.pop();

            if(curr_num % 7 == 0)
            {
                cout << "LUCKY";
                flag = true;
                break;
            }
        }

        if(!flag)
        {
            cout << "UNLUCKY";  
        }
        cout << "\n";
    }
}