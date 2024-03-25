#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int min_cost = INT32_MAX;
    for(int i = 0; i < n-1; i++)
    {
        int cost = 0;
        cost += (arr[i]+arr[i+1]) * x;
        min_cost = min(min_cost, cost);
    }

    cout << min_cost;
}