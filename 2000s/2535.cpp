#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <pair <int, pair <int, int>>> arr(n);
    vector <int> medal(n+1);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].second.first >> arr[i].second.second >> arr[i].first;
    }
    sort(arr.begin(), arr.end(), greater<>());

    int medal_count = 0;
    for(int i = 0; i < n; i++)
    {
        int country = arr[i].second.first;
        int seq = arr[i].second.second;
        int score = arr[i].first;

        if(medal[country] < 2)
        {
            medal[country]++;
            medal_count++;
            cout << country << " " << seq << "\n";
        }

        if(medal_count == 3)
        {
            break;
        }
    }
}