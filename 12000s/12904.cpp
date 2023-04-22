#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    bool flag = false;
    while(s.length() < t.length())
    {
        if(t.back() == 'B')
        {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
        else if(t.back() == 'A')
        {
            t.pop_back();
        }

        if(s == t)
        {
            flag = true;
            break;
        }
    }

    cout << flag;
}