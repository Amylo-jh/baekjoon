#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int c, n;
    cin >> c >> n;
    vector <pair <int, int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    vector <int> bag(100001);
    bag.assign(100001, INT32_MAX);
    bag[0] = 0;
    for(int i = 0; i < n; i++)
    {
        int people = arr[i].second;
        int cost = arr[i].first;
        for(int j = 1; j <= 100000; j++)
        {
            bag[j] = min(bag[j], bag[max(0, (j-people))]+cost);
        }
    }

    int min_cost = INT32_MAX;
    for(int i = c; i <= 100000; i++)
    {
        min_cost = min(min_cost, bag[i]);
    }
    cout << min_cost;
}