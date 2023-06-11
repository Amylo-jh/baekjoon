#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <vector <int>> singers(n+1);
    vector <int> in_degree(n+1);
    vector <int> visited(n+1);
    vector <int> result;
    for(int i = 0; i < m; i++)
    {
        int count;
        cin >> count;

        int prev_singer;
        cin >> prev_singer;
        for(int j = 1; j < count; j++)
        {   
            int temp;
            cin >> temp;
            in_degree[temp]++;
            singers[prev_singer].push_back(temp);
            prev_singer = temp;
        }
    }

    queue <int> q;
    for(int i = 1; i <= n; i++)
    {
        if(in_degree[i] == 0)
        {
            q.push(i);
            visited[i] = true;
        }
    }

    while(!q.empty())
    {
        int curr_node = q.front();
        result.push_back(curr_node);
        q.pop();

        for(int i : singers[curr_node])
        {
            in_degree[i]--;
            if(in_degree[i] == 0)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    bool flag = true;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            flag = false;
        }
    }
    if(result.size() != n)
    {
        flag = false;
    }

    if(flag)
    {
        for(int i = 0; i < n; i++)
        {
            cout << result[i] << "\n";
        }
    }
    else
    {
        cout << 0;
    }
}