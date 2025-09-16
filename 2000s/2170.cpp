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
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());

    int answer = 0;
    int pos1 = arr[0].first, pos2 = arr[0].second;
    for(int i = 1; i < n; i++)
    {
        if(arr[i].first > pos2)
        {
            answer += pos2 - pos1;
            pos1 = arr[i].first;
            pos2 = arr[i].second;
        }
        else
        {
            pos2 = max(pos2, arr[i].second);
        }
    }

    answer += pos2 - pos1;
    cout << answer;
}