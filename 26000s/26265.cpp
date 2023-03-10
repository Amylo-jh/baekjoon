#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (pair <string, string> a, pair <string, string> b)
{
    if(a.first < b.first)
    {
        return a.first < b.first;
    }
    else if(a.first == b.first)
    {
        return a.second > b.second;
    }

    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector <pair <string, string>> lists(n);
    for(int i = 0; i < n; i++)
    {
        cin >> lists[i].first >> lists[i].second;
    }

    sort(lists.begin(), lists.end(), comp);

    for(int i = 0; i < n; i++)
    {
        cout << lists[i].first << " " << lists[i].second << "\n";
    }
}