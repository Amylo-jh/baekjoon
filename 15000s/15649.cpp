#include <iostream>
#include <vector>

using namespace std;

vector <int> arr;
vector <bool> visited;

void dfs(int n, int m, int d)
{
    if(d == m)
    {
        for(int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                arr[d] = i;
                dfs(n, m, d+1);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    arr.resize(m);
    visited.resize(n+1);

    dfs(n, m, 0);
}