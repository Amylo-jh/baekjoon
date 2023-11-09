#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int>> node;
vector <int> path;
vector <int> order;
vector <bool> visited;
vector <int> answer;
int seq = 1;

bool comp (int a, int b)
{
    return order[a] < order[b];
}

void dfs(int k)
{
    visited[k] = true;
    answer[seq] = k;
    seq++;

    for(int i : node[k])
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    node.resize(n+1);
    path.resize(n+1);
    order.resize(n+1);
    visited.resize(n+1);
    answer.resize(n+1);
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        int n;
        cin >> n;
        path[i] = n;
        order[n] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        sort(node[i].begin(), node[i].end(), comp);
    }

    dfs(1);
    for(int i = 1; i <= n; i++)
    {
        if(path[i] != answer[i])
        {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
}