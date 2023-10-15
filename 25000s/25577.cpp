#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> arr;
vector <int> sorted;
vector <bool> visited;

int dfs(int node, int count)
{
    visited[node] = true;
    if(visited[arr[node]])
    {
        return count;
    }
    else
    {
        count = dfs(arr[node], count+1);
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    arr.resize(n);
    sorted.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sorted[i] = arr[i];
    }
    sort(sorted.begin(), sorted.end());
    for(int i = 0; i < n; i++)
    {
        arr[i] = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
    }
    
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            int x = i;
            while(!visited[x])
            {
                visited[x] = true;
                x = arr[x];
                count++;
            }
            count--;
        }
    }

    cout << count;
}