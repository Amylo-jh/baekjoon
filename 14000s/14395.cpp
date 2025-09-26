#include <iostream>
#include <map>
#include <string>
#include <queue>

using namespace std;

bool comp(string a, string b)
{
    if(a.length() != b.length())
    {
        return a.length() < b.length();    
        
    }
    return a < b;
}

int main()
{
    long long s, t, m;
    cin >> s >> t;
    m = max(s, t);
    if(s == t)
    {
        cout << 0;
        return 0;
    }

    map <long long, string> mp;
    mp[1] = "/";
    mp[s] = "";
    queue <long long> bfs_queue;
    bfs_queue.push(s);
    bfs_queue.push(1);

    while(!bfs_queue.empty())
    {
        long long curr = bfs_queue.front();
        bfs_queue.pop();

        if(curr*2 <= m)
        {
            if(mp.find(curr*2) == mp.end())
            {
                mp[curr*2] = mp[curr] + "+";
                bfs_queue.push(curr*2);
            }
            else if(comp(mp[curr] + "+",mp[curr*2]))
            {
                mp[curr*2] = mp[curr] + "+";
                bfs_queue.push(curr*2);
            }
        }

        if(curr*curr <= m)
        {
            if(mp.find(curr*curr) == mp.end())
            {
                mp[curr*curr] = mp[curr] + "*";
                bfs_queue.push(curr*curr);
            }
            else if(comp(mp[curr] + "*",mp[curr*curr]))
            {
                mp[curr*curr] = mp[curr] + "*";
                bfs_queue.push(curr*curr);
            }
        }
    }

    if(mp.find(t) == mp.end())
    {
        cout << -1;
    }
    else
    {
        cout << mp[t];
    }
}