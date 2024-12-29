#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map <string, int> mp;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    for(int i = 1; i < n; i++)
    {
        string s;
        cin >> s;
        mp[s]--;
    }

    for(auto it : mp)
    {
        if(it.second != 0)
        {
            cout << it.first;
        }
    }
}