#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    stack <char> stk;

    for(int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        
        if(stk.size() >= 3 && stk.top() == 'A' && ch == 'P')
        {
            char temp_ch[3];
            for(int j = 0; j < 3; j++)
            {
                temp_ch[j] = stk.top();
                stk.pop();
            }

            if(temp_ch[0] == 'A' && temp_ch[1] == 'P' && temp_ch[2] == 'P')
            {
            }
            else
            {
                for(int j = 2; j >= 0; j--)
                {
                    stk.push(temp_ch[j]);
                }
            }
        }
        stk.push(ch);
    }

    if(stk.size() == 1 && stk.top() == 'P')
    {
        cout << "PPAP";
    }
    else
    {
        cout << "NP";
    }
}