#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, p;
    cin >> s >> p;

    int count = 0;
    int idx = 0;
    int plen = p.length();
    int slen = s.length();
    while(idx < plen)
    {
        bool is_match = false;
        int max_match = 0;
        for(int i = 0; i < slen; i++)
        {
            if(p[idx] == s[i])
            {
                int match = 1;
                for(int j = i+1; j < slen; j++)
                {
                    if(p[idx+match] == s[j])
                    {
                        match++;
                    }
                    else
                    {
                        break;
                    }
                }
                max_match = max(max_match, match);
            }
        }
        count++;
        idx += max_match;
    }
    cout << count;
}