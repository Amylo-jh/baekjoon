#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <vector <int>> friends(n+1);
    vector <bool> visited(n+1);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    int count = 0;
    queue <int> q;
    visited[1] = true;
    for(int i : friends[1])
    {
        if(!visited[i])
        {
            q.push(i);
            visited[i] = true;
            count++;
        }
    }

    while(!q.empty())
    {
        for(int i : friends[q.front()])
        {
            if(!visited[i])
            {
                visited[i] = true;
                count++;
            }
        }
        q.pop();
    }

    cout << count;
}