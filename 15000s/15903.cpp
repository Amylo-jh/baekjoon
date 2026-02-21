#include <iostream>
#include <queue>

using namespace std;

int main()
{
    long long n, m, tmp1, tmp2, sum = 0;
    priority_queue<long long> pq;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp1;
        pq.push(-tmp1);
    }
    while (m--)
    {
        tmp1 = pq.top();
        pq.pop();
        tmp2 = pq.top();
        pq.pop();
        pq.push(tmp1 + tmp2);
        pq.push(tmp1 + tmp2);
    }
    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }
    cout << -sum;
}