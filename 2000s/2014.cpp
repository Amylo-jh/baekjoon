#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main()
{
    int n ,m;
    long long max_value = 0;
    cin >> n >> m;
    vector <long long> prime(n);
    priority_queue <long long, vector <long long>, greater<long long>> pq;
    map <long long, bool> check;
    for(int i = 0; i < n; i++)
    {
        cin >> prime[i];
        pq.push(prime[i]);
        check[prime[i]] = true;
        max_value = max(max_value, prime[i]);
    }

    int count = 1;
    long long num = 0;
    
    for(int i = 1; i < m; i++)
    {
        num = pq.top();
        pq.pop();

        for(int j : prime)
        {
            long long next = num * j;
            if(check.count(next))
            {
                continue;
            }
            if(pq.size() > m && max_value < next)
            {
                continue;
            }
            pq.push(next);
            check[next] = true;
            max_value = max(max_value, next);
        }
        count++;
    }

    cout << pq.top();
}