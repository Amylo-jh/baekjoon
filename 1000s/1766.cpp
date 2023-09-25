#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int>> arr(n+1);
    vector <int> indegree(n+1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        indegree[b]++;
    }

    priority_queue <int, vector <int>, greater<>> pq;
    for(int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0)
        {
            pq.push(i);
        }
    }
    while(!pq.empty())
    {
        int top = pq.top();
        cout << top << " ";
        pq.pop();

        for(int i = 0; i < arr[top].size(); i++)
        {
            indegree[arr[top][i]]--;
            if(indegree[arr[top][i]] == 0)
            {
                pq.push(arr[top][i]);
            }
        }
    }
}