#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    string t;

    while(cin >> s >> t)
    {
        int s_num = s.length();
        int t_num = t.length();
        int s_pointer = 0;

        for(int i = 0; i < t_num; i++)
        {
            if(s[s_pointer] == t[i])
            {
                s_pointer++;
            }
        }

        if(s_pointer == s_num)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}