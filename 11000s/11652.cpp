#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    map <long long, int> hashtable;
    vector <pair <int, long long>> arr;
    for(int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        hashtable[temp]++;
    }

    for(auto i : hashtable)
    {
        arr.push_back({i.second, i.first});
    }
    sort(arr.begin(), arr.end(), greater<>());
    
    int max_value = 0;
    long long max_number = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i].first >= max_value)
        {
            max_value = arr[i].first;
            max_number = arr[i].second;
        }
    }
    cout << max_number;
}