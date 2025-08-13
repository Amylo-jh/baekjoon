#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    int k, len;
    cin >> str >> k;
    len = str.length();
    for(int i = 0; i < len; i++)
    {
        if('a' <= str[i] && str[i] <= 'z')
        {
            str[i] = str[i] - ('a' - 'A');
        }
    }
    vector <bool> visited(len);
    vector <int> result;
    for(int i = 0; i < len; i++)
    {
        if(!visited[i])
        {
            char ch = str[i];
            int combo = 0;
            bool flag = true;
            for(int j = i; j < len; j++)
            {
                if(str[j] == ch && flag)
                {
                    combo++;
                    visited[j] = true;
                }
                else if(str[j] == ch && !flag)
                {
                    visited[j] = true;
                }
                else
                {
                    flag = false;
                }
            }
            if(combo >= k)
            {
                result.push_back(1);
            }
            else
            {
                result.push_back(0);
            }
        }
    }

    for(auto i : result)
    {
        cout << i;
    }
}