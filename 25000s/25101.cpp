#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    priority_queue <pair <int, int>> pq;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pq.push({temp, -i});
    }

    while(k--)
    {
        if(pq.top().first > 100)
        {
            pq.push({pq.top().first-100, pq.top().second});
            pq.pop();
        }
        else
        {
            cout << "impossible";
            return 0;
        }
    }

    vector <int> arr(n);
    while(!pq.empty())
    {
        arr[-pq.top().second] = pq.top().first;
        pq.pop();
    }
    for(int i : arr)
    {
        cout << i << " ";
    }
}