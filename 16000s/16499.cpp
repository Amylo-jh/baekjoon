#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map <vector <int>, int> mp;
    for(int i = 0; i < n; i++)
    {
        vector <int> temp(26);
        string str;
        cin >> str;

        for(int j = 0; j < str.length(); j++)
        {
            temp[str[j] - 'a']++;
        }

        mp[temp]++;
    }

    cout << mp.size();
}