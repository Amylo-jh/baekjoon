#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, m, k, tmp;
    cin >> n >> m >> k;
    priority_queue <int, vector <int>, greater<>> pq;
    for(int i = 0; i < m; i++)
    {
        pq.push(0);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        pq.push(pq.top() + tmp);
        pq.pop();   
    }
    if(pq.top() <= k)
    {
        cout << "WAIT";
    }
    else
    {
        cout << "GO";
    }
}