#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    priority_queue<pair <int, long long>, vector <pair <int, long long>>, greater<>> pq;
    pq.push({1, a});

    bool flag = false;
    while(!pq.empty())
    {
        int seq = pq.top().first;
        long long num = pq.top().second;
        pq.pop();

        if(num == b)
        {
            cout << seq;
            flag = true;
            break;
        }
        else
        {
            long long nextnum = num*2;
            if(nextnum <= b)
            {
                pq.push({seq+1, num*2});
            }
            nextnum = num*10+1;
            if(nextnum <= b)
            {
                pq.push({seq+1, num*10+1});
            }
        }
    }

    if(flag)
    {
        return 0;
    }
    cout << -1;
}