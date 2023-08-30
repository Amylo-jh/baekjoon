#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <pair <int, int>> lower;
    vector <pair <int, int>> sweep;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a > b)
        {
            lower.push_back({b, a});
        }
    }
    sort(lower.begin(), lower.end());

    if(lower.size() != 0)
    {
        int start = lower[0].first;
        int end = lower[0].second;
        for(int i = 1; i < lower.size(); i++)
        {
            if(lower[i].first <= end)
            {
                end = max(end, lower[i].second);
            }
            else
            {
                sweep.push_back({start, end});
                start = lower[i].first;
                end = lower[i].second;
            }
        }
        sweep.push_back({start, end});
    }

    long long total_dist = m;
    for(int i = 0; i < sweep.size(); i++)
    {
        total_dist += (sweep[i].second - sweep[i].first)*2;
    }

    cout << total_dist;
}