#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> area(n);
    vector <bool> visited(n);
    for(int i = 0; i < n; i++)
    {
        cin >> area[i];
    }

    queue <pair <int, int>> q;
    q.push({0, 0});
    visited[0] = true;

    int result = -1;
    while(!q.empty())
    {
        int pos = q.front().first;
        int seq = q.front().second;
        q.pop();

        if(pos == n-1)
        {
            result = seq;
            break;
        }

        for(int i = pos + area[pos]; i > pos; i--)
        {
            if(i < n && !visited[i])
            {
                visited[i] = true;
                q.push({i, seq+1});
            }
        }
    }

    if(result < 0)
    {
        cout << result;
    }
    else
    {
        cout << result;
    }
}