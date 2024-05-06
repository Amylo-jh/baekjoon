#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    map <int, pair <int, int>> m;
    vector <pair <int, pair <int, int>>> arr;

    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if(m[t].first == 0)
        {
            m[t].second = INT32_MIN;
        }
        m[t].first++;
        m[t].second = max(m[t].second, -i);
    }

    for(auto it = m.begin(); it != m.end(); it++)
    {
        arr.push_back({it->second.first, {it->second.second, it->first}});
    }

    sort(arr.begin(), arr.end(), greater <pair <int, pair <int, int>>>());
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[i].first; j++)
        {
            cout << arr[i].second.second << " ";
        }
    }
}