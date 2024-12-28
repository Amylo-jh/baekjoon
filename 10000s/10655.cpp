#include <iostream>
#include <vector>

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
        cin >> arr[i].first >> arr[i].second;
    }

    int total_dist = 0;
    int max_reduced_dist = 0;
    for(int i = 1; i < n-1; i++)
    {
        int original_dist = abs(arr[i-1].first-arr[i].first) + abs(arr[i-1].second-arr[i].second) + abs(arr[i].first-arr[i+1].first) + abs(arr[i].second-arr[i+1].second);
        int reduced_dist = abs(arr[i-1].first-arr[i+1].first) + abs(arr[i-1].second-arr[i+1].second);
        max_reduced_dist = max(max_reduced_dist, original_dist-reduced_dist);
    }
    for(int i = 1; i < n; i++)
    {
        total_dist += abs(arr[i-1].first-arr[i].first) + abs(arr[i-1].second-arr[i].second);
    }

    cout << total_dist-max_reduced_dist;
}