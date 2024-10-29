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
    int max_height = 0;
    int max_pos = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        if(arr[i].second > max_height)
        {
            max_height = arr[i].second;
            max_pos = arr[i].first;;
        }
    }
    sort(arr.begin(), arr.end());

    int answer = max_height;
    int curr_height = arr[0].second;
    for(int i = 0; arr[i].first < max_pos; i++)
    {
        int dist = arr[i+1].first - arr[i].first;
        curr_height = max(curr_height, arr[i].second);

        answer += dist * curr_height;
    }
    curr_height = arr[n-1].second;
    for(int i = n-1; arr[i].first > max_pos; i--)
    {
        int dist = arr[i].first - arr[i-1].first;
        curr_height = max(curr_height, arr[i].second);

        answer += dist * curr_height;
    }

    cout << answer;
}