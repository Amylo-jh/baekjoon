#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool comp(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b)
{
    if(a.first.second == b.first.second)
    {
        return a.first.first < b.first.first;
    }
    return a.first.second < b.first.second;
}

int main()
{
    int n, c, m;
    cin >> n >> c >> m;
    vector <pair <pair <int, int>, int>> arr(m);
    vector <int> truck(n+1);
    for(int i = 0; i < m; i++)
    {
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), comp);

    int answer = 0;
    for(int i = 0; i < m; i++)
    {
        int from = arr[i].first.first;
        int to = arr[i].first.second;
        int cost = arr[i].second;
        int max_truck = 0;
        
        for(int j = from; j < to; j++)
        {
            max_truck = max(truck[j], max_truck);
        }
        int cap = min(cost, c - max_truck);

        for(int j = from; j < to; j++)
        {
            truck[j] += cap;
        }
        answer += cap;
    }

    cout << answer;
}