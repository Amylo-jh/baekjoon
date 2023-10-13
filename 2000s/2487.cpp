#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector <int> arr;
vector <bool> visited;

int dfs(int i, int count)
{
    visited[i] = true;
    if(!visited[arr[i]])
    {
        count = dfs(arr[i], count+1);
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    arr.resize(n+1);
    visited.resize(n+1);
    vector <int> total_counts;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        arr[temp] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            int count = dfs(i, 1);
            total_counts.push_back(count);
        }
    }

    long long answer = total_counts[0];
    for(int i = 1; i < total_counts.size(); i++)
    {
        answer = lcm(answer, total_counts[i]);
    }

    cout << answer;
}