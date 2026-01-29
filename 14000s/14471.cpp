#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, m, answer = 0;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a < n)
        {
            pq.push(n - a);
        }
    }
    while (pq.size() > 1)
    {
        answer += pq.top();
        pq.pop();
    }
    cout << answer;
}