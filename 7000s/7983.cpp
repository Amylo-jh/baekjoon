#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair <int, int> a, pair <int, int> b)
{
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector <pair <int, int>> tasks(n);
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tasks[i] = {b-a, b};
    }

    sort(tasks.begin(), tasks.end(), comp);

    int max_date = tasks[0].first;
    for(int i = 1; i < n; i++)
    {
        if(max_date < tasks[i].second)
        {
            tasks[i].first -= tasks[i].second - max_date;
        }
        max_date = tasks[i].first;
    }

    cout << max_date;
}