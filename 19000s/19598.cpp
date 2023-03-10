#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector <pair <int, int>> meeting(n);
    for(int i = 0; i < n; i++)
    {
        cin >> meeting[i].first >> meeting[i].second;
    }
    sort(meeting.begin(), meeting.end());

    int max_meetingroom = 0;
    priority_queue <int, vector<int>, greater<>> pq;
    
    for(int i = 0; i < n; i++)
    {
        while(!pq.empty() && pq.top() <= meeting[i].first)
        {
            pq.pop();
        }
        pq.push(meeting[i].second);
        int pq_size = pq.size();
        max_meetingroom = max(max_meetingroom, pq_size);
    }

    cout << max_meetingroom;
}