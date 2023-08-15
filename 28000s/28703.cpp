#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    priority_queue <int, vector <int>, greater<>> pq;
    
    int p_max = 0;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
        p_max = max(p_max, temp);
    }

    int min_diff = p_max - pq.top();
    int max_value = p_max;

    while(pq.top() <= p_max)
    {
        int curr_num = pq.top();
        pq.pop();
        curr_num *= 2;

        pq.push(curr_num);
        max_value = max(max_value, curr_num);
        min_diff = min(max_value - pq.top(), min_diff);
    }

    cout << min_diff;
}