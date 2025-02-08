#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    while(1)
    {
        string s;
        cin >> s;

        if(s == "*")
        {
            break;
        }

        int len = s.length();
        bool flag = false;
        for(int i = 1; i < len; i++)
        {
            if(flag)
            {
                break;
            }
            map <string, int> mp;
            for(int j = 0; j < len-i; j++)
            {
                string sub = s.substr(j, 1);
                sub += s.substr(j+i, 1);

                if(mp[sub])
                {
                    cout << s << " is NOT surprising.";
                    flag = true;
                    break;
                }
                else
                {
                    mp[sub] = 1;
                }
            }
        }

        if(!flag)
        {
            cout << s << " is surprising.";
        }
        cout << "\n";
    }
}