#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector <vector <int>> node;
vector <bool> visited;
stack <int> stk;
long long sum = 0;
long long seq = 1;
void dfs(int curr)
{
    int depth = stk.size()-1;
    sum += depth * seq;
    seq++;
    for(int i : node[curr])
    {
        if(!visited[i])
        {
            visited[i] = true;
            stk.push(i);
            dfs(i);
        }
    }
    stk.pop();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;
    node.resize(n+1);
    visited.resize(n+1, false);
    stk.push(r);
    visited[r] = true;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    for(int i = 0; i <= n; i++)
    {
        sort(node[i].begin(), node[i].end());
    }

    dfs(r);
    cout << sum;
}