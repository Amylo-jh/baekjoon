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
    
    int n;
    cin >> n;

    vector <pair <int, int>> line(n);
    for(int i = 0; i < n; i++)
    {
        cin >> line[i].first >> line[i].second;
    }
    sort(line.begin(), line.end());

    int counter = 0;
    priority_queue <int, vector<int>, greater<>> pq;
    for(int i = 0; i < n; i++)
    {
        int start_pos = line[i].first;
        int end_pos = line[i].second;
        pq.push(end_pos);
        
        while(start_pos >= pq.top())
        {
            pq.pop();
        }
        int pq_size = pq.size();
        counter = max(counter, pq_size);
    }

    cout << counter;
}