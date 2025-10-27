#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    map <string, int> mp;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if(mp[str] == 0)
        {
            count++;
            string tmpstr = str;
            for(int j = 0; j < str.length(); j++)
            {
                tmpstr = tmpstr.substr(1, str.length()-1) + tmpstr[0];
                mp[tmpstr]++;
            }
        }
    }
    cout << count;
}