#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set <string> set_string;
    string prev_last = "";
    string next_first = "";
    bool flag1 = false;
    bool flag2 = false;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        if(str == "?")
        {
            flag1 = true;
            flag2 = true;
            continue;
        }
        if(!flag1)
        {
            prev_last = str.substr(str.length()-1, 1);
        }
        if(flag2)
        {
            next_first = str.substr(0, 1);
            flag2 = false;
        }

        set_string.insert(str);
    }

    int m;
    bool flag = false;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        string str;
        cin >> str;

        if(set_string.count(str) || flag)
        {
            continue;
        }

        if(next_first == "" && prev_last == "")
        {
            cout << str;
            flag = true;
            continue;
        }
        if(prev_last == "")
        {
            if(str.substr(str.length()-1, 1) == next_first)
            {
                cout << str;
                flag = true;
            }
        }
        else if(next_first == "")
        {
            if(str.substr(0, 1) == prev_last)
            {
                cout << str;
                flag = true;
            }
        }
        else
        {
            if(str.substr(0, 1) == prev_last && str.substr(str.length()-1, 1) == next_first)
            {
                cout << str;
                flag = true;
            }
        }
    }
}