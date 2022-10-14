#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <bool> prime(10000);

void init()
{
    prime.assign(10000, true);
    prime[0] = false;
    prime[1] = false;

    for(int i = 2; i < 10000; i++)
    {
        if(prime[i])
        {
            for(int j = 2; i*j < 10000; j++)
            {
                prime[i*j] = false;
            }
        }
    }
}

int main()
{
    init();

    int tc;
    cin >> tc;

    while(tc--)
    {
        int start, end;
        cin >> start >> end;

        int count = 0;
        vector <bool> visited(10000);
        queue <int> bfs_queue;
        queue <int> bfs_queue2;
        bfs_queue.push(start);
        visited[start] = true;

        bool flag = false;
        while(!bfs_queue.empty())
        {
            int front = bfs_queue.front();
            visited[front] = true;
            bfs_queue.pop();

            if(front == end)
            {
                flag = true;
                break;
            }
            
            int candidate_num = front;
            candidate_num /= 10;
            candidate_num *= 10;
            for(int i = 0; i < 10; i++)
            {
                if(prime[candidate_num] && !visited[candidate_num])
                {
                    visited[candidate_num] = true;
                    bfs_queue2.push(candidate_num);
                }
                candidate_num++;
            }

            candidate_num = front;
            candidate_num /= 100;
            candidate_num *= 100;
            candidate_num += (front%10);
            for(int i = 0; i < 10; i++)
            {
                if(prime[candidate_num] && !visited[candidate_num])
                {
                    visited[candidate_num] = true;
                    bfs_queue2.push(candidate_num);
                }
                candidate_num += 10;
            }

            candidate_num = front;
            candidate_num /= 1000;
            candidate_num *= 1000;
            candidate_num += (front % 100);
            for(int i = 0; i < 10; i++)
            {
                if(prime[candidate_num] && !visited[candidate_num])
                {
                    visited[candidate_num] = true;
                    bfs_queue2.push(candidate_num);
                }
                candidate_num += 100;
            }

            candidate_num = front;
            candidate_num %= 1000;
            candidate_num += 1000;
            for(int i = 1; i < 10; i++)
            {
                if(prime[candidate_num] && !visited[candidate_num])
                {
                    visited[candidate_num] = true;
                    bfs_queue2.push(candidate_num);
                }
                candidate_num += 1000;
            }

            if(bfs_queue.empty())
            {
                bfs_queue = bfs_queue2;
                bfs_queue2 = {};
                count++;
            }
        }

        if(flag)
        {
            cout << count;
        }
        else
        {
            cout << "Impossible";
        }
        cout << "\n";
    }
}