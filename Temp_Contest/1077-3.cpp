#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue <long long, vector <long long>, greater<>> pq;
    
    long long max_value = 0;
    for(int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        pq.push(temp);
        max_value = max(max_value, temp);
    }

    long long min_diff = max_value - pq.top();

    int max_count = max_value / pq.top();
    for(int i = 0; i < max_count; i++)
    {
        long long curr_num = pq.top();
        pq.pop();
        curr_num *= 2;

        if(curr_num < 0)
        {
            break;
        }
        max_value = max(max_value, curr_num);
        pq.push(curr_num);

        min_diff = min(max_value - pq.top(), min_diff);
    }

    cout << min_diff;
}