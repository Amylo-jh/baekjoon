#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set <string> st;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        st.insert(s);
    }

    for(string s : st)
    {
        reverse(s.begin(), s.end());
        if(st.find(s) != st.end())
        {
            cout << s.length() << " " << s[s.length()/2];
            break;
        }
    }
}