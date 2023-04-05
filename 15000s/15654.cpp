#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector <int> arr;
vector <bool> visited;

void backtracking(vector <int> btrk, int depth)
{
    if(depth == m)
    {
        for(int i = 0; i < m; i++)
        {
            cout << btrk[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                btrk[depth] = arr[i];
                backtracking(btrk, depth+1);
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
    
    cin >> n >> m;

    arr.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++)
    {
        visited[i] = true;
        vector <int> btrk(n);
        btrk[0] = arr[i];
        backtracking(btrk, 1);
        visited[i] = false;
    }
}