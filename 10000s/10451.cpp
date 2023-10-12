#include <iostream>
#include <vector>

using namespace std;

int arr[1001];
int visited[1001];

void clear()
{
    for(int i = 0; i < 1001; i++)
    {
        arr[i] = 0;
        visited[i] = 0;
    }
}

int dfs(int node)
{
    int next = arr[node];
    visited[node] = true;
    if(visited[next])
    {
        return 1;
    }

    return dfs(next);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--)
    {
        int n, count = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                count += dfs(i);
            }
        }

        cout << count << "\n";
        clear();
    }
}