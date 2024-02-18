#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    cin >> n >> l;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    priority_queue <pair <int, int>, vector <pair <int, int>>, greater<>> pq;
    for(int i = 0; i < n; i++)
    {
        pq.push({arr[i], i});
        while(pq.top().second <= i-l)
        {
            pq.pop();
        }
        cout << pq.top().first << " ";
    }
}