#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool comp(pair <int, int> a, pair <int, int> b)
{
    if(a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main()
{
    int n;
    cin >> n;
    vector <pair <int, int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr.begin(), arr.end(), comp);

    priority_queue <int, vector <int>, greater<>> pq;
    for(int i = 0; i < n; i++)
    {
        int day = arr[i].first;
        int money = arr[i].second;

        if(day > pq.size())
        {
            pq.push(money);
        }
        else
        {
            if(pq.top() < money)
            {
                pq.pop();
                pq.push(money);
            }
        }
    }

    int total_money = 0;
    while(!pq.empty())
    {
        total_money += pq.top();
        pq.pop();
    }

    cout << total_money;
}   