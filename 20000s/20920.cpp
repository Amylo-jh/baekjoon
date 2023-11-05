#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool comp(pair <string, int> a, pair <string, int> b)
{
    if(a.second == b.second)
    {
        if(a.first.length() == b.first.length())
        {
            return a.first < b.first;
        }
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector <pair <string, int>> arr;
    map <string, int> hash;

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if(str.length() >= m)
        {
            hash[str]++;
        }
    }
    for(pair <string, int> i : hash)
    {
        arr.push_back(i);        
    }

    sort(arr.begin(), arr.end(), comp);

    for(auto i : arr)
    {
        cout << i.first << "\n";
    }
}