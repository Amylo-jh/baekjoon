#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool comp(pair <int, int> a, pair <int, int> b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n;
    vector <pair <int, int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        arr[i].first = a;
        arr[i].second = b;
    }
    cin >> d;

    sort(arr.begin(), arr.end(), comp);

    int counter = 0;
    int start = arr[0].first;
    int end = arr[0].first;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater<> > q;
    for(int i = 0; i < n; i++)
    {
        int diff = arr[i].second - arr[i].first;
        if(diff > d)
        {
            continue;
        }
        else
        {
            end = arr[i].second;
            q.push(arr[i]);
        }

        while(!q.empty() && q.top().first < end - d)
        {
            q.pop();
        }

        start = q.top().first;
        counter = max(counter, int(q.size()));
    }

    cout << counter;
}