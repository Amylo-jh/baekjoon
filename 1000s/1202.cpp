#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    // weight, value;
    vector <pair <int, long long>> jewel(n);
    vector <int> bag(k);
    priority_queue <pair <long long, int>> pq;
    long long total_value = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> jewel[i].first >> jewel[i].second;
    }
    for(int i = 0; i < k; i++)
    {
        cin >> bag[i];
    }
    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());
    
    int j_pos = 0;
    for(int i = 0; i < k; i++)
    {
        while(jewel[j_pos].first <= bag[i] && j_pos < n)
        {
            pq.push({jewel[j_pos].second, jewel[j_pos].first});
            j_pos++;
        }
        if(!pq.empty())
        {
            total_value += pq.top().first;
            pq.pop();
        }
    }

    cout << total_value;
}