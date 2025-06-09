#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector <pair <int, int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].second;
    }
    arr.push_back({0, 0});
    sort(arr.begin(), arr.end(), greater<>());

    int time = max(arr[0].first, arr[0].second);
    int pos = arr[0].first;

    for(int i = 1; i <= n; i++)
    {
        int diff = pos - arr[i].first;
        pos = arr[i].first;
        time += diff;

        if(time < arr[i].second)
        {
            time = arr[i].second;
        }
    }
    cout << time;
}