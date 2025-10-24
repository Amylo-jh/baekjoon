#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    map <string, pair <int, int>> mp;
    vector <pair <int, string>> arr;
    string str;
    int count = 0;
    while(1)
    {
        getline(cin, str);
        if(str == "0")
        {
            break;
        }
        mp[str].second++;
        if(mp[str].first == 0)
        {
            mp[str].first = count+1;
        }
        count++;
    }
    for(auto i : mp)
    {
        arr.push_back({i.second.first, i.first});
    }
    sort(arr.begin(), arr.end());
    for(auto i : arr)
    {
        cout << i.second << ": " << mp[i.second].second << "\n";
    }
    cout << "Grand Total: " << count;
}