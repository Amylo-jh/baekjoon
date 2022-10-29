#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    priority_queue<long long, vector <long long>, greater<>> pq;
    for(int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        pq.push(temp);
    }

    long long total_comp = 0;
    for(int i = 1; i < n; i++)
    {
        long long a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        a = a + b;
        total_comp += a;
        pq.push(a);
    }

    cout << total_comp;
}