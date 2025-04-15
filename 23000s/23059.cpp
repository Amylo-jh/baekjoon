#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    map <string, int> mp;
    map <string, vector <string>> next_item;
    vector <string> buyable_items;
    vector <string> next_buyable_items;
    vector <string> answer;
    for(int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        mp[a];
        mp[b]++;
        next_item[a].push_back(b);
    }
    for(auto i : mp)
    {
        if(i.second == 0)
        {
            buyable_items.push_back(i.first);
        }
    }

    int purchased_items = 0;
    while(buyable_items.size() != 0)
    {
        sort(buyable_items.begin(), buyable_items.end());
        for(auto i : buyable_items)
        {
            purchased_items++;
            answer.push_back(i);
            for(auto j : next_item[i])
            {
                mp[j]--;
                if(mp[j] == 0)
                {
                    next_buyable_items.push_back(j);
                }
            }
        }

        buyable_items = next_buyable_items;
        next_buyable_items = {};
    }

    if(purchased_items == mp.size())
    {
        for(auto i : answer)
        {
            cout << i << "\n";
        }
    }
    else
    {
        cout << -1;
    }
}