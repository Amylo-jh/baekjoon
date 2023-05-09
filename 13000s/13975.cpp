#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;

    while(tc--)
    {
        priority_queue <long long, vector<long long>, greater<> > pq;
        int n;
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            long long temp;
            cin >> temp;
            pq.push(temp);
        }

        long long cost = 0;
        for(int i = 1; i < n; i++)
        {
            long long a, b;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            cost += a+b;
            pq.push(a+b);
        }

        cout << cost << "\n";
    }
}