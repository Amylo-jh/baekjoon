#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    list<char> strlist(str.begin(), str.end());

    int query;
    cin >> query;

    list<char>::iterator cursor = strlist.end();
    while(query--)
    {
        char cmd;
        cin >> cmd;

        if(cmd == 'L')
        {
            if(cursor != strlist.begin())
            {
                cursor--;
            }
        }
        else if(cmd == 'D')
        {
            if(cursor != strlist.end())
            {
                cursor++;
            }
        }
        else if(cmd == 'B')
        {
            if(cursor != strlist.begin())
            {
                cursor = strlist.erase(--cursor);
            }
        }
        else if(cmd == 'P')
        {
            char c;
            cin >> c;

            strlist.insert(cursor, c);
        }
    }

    for(auto c : strlist)
    {
        cout << c;
    }
}