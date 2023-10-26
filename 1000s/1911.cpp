#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;

    vector <pair <int, int>> hole(n);
    for(int i = 0; i < n; i++)
    {
        cin >> hole[i].first >> hole[i].second;
    }
    sort(hole.begin(), hole.end());

    int end_pos = 0;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        int start = max(end_pos, hole[i].first);
        int end = hole[i].second;
        int len = end - start;

        if(len <= 0)
        {
            continue;
        }
        if(len % l)
        {
            end_pos = start + l*((len / l)+1);
            count++;
        }
        count += len / l;
    }

    cout << count;
}