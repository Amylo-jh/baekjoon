#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, x;
bool visited[100001];
vector <vector <int>> forward_link, reverse_link;
int forward_count = 0;
int reverse_count = 0;

void forward_dfs(int curr_node)
{
    if(visited[curr_node])
    {
        return;
    }

    visited[curr_node] = true;
    forward_count++;

    for(int i : forward_link[curr_node])
    {
        forward_dfs(i);
    }
}

void reverse_dfs(int curr_node)
{
    if(visited[curr_node])
    {
        return;
    }

    visited[curr_node] = true;
    reverse_count++;

    for(int i : reverse_link[curr_node])
    {
        reverse_dfs(i);
    }
}

void reset_visited()
{
    for(int i = 0; i <= n; i++)
    {
        visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> x;
    forward_link.resize(n+1);
    reverse_link.resize(n+1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        forward_link[a].push_back(b);
        reverse_link[b].push_back(a);
    }

    forward_dfs(x);
    reset_visited();
    reverse_dfs(x);

    cout << reverse_count << " " << n-forward_count+1;
}