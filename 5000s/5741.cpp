#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    while(1)
    {
        int tc;
        cin >> tc;
        if(!tc)
        {
            break;
        }

        // teamname, score, goal diff
        map <string, pair <int, int>> team;
        for(int i = 0; i < tc; i++)
        {
            string ta, tb, tmp;
            int sa, sb;

            cin >> ta >> sa >> tmp >> sb >> tb;
            if(sa > sb)
            {
                team[ta].first += 3;
            }
            else if(sa < sb)
            {
                team[tb].first += 3;
            }
            else
            {
                team[ta].first++;
                team[tb].first++;
            }
            team[ta].second += sa-sb;
            team[tb].second += sb-sa;
        }

        vector <pair <pair <int, int>, string>> arr;
        for(auto i : team)
        {
            arr.push_back({{i.second.first, i.second.second}, i.first});
        }
        sort(arr.begin(), arr.end(), greater<>());

        for(auto i : arr)
        {
            cout << i.first.first << " " << i.second << "\n";
        }
        cout << "\n";
    }
}