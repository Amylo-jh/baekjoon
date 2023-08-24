#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
int pos = 0;

string solve()
{
    stack <char> stk;
    string result = "";
    while(pos < str.length())
    {
        if('A' <= str[pos] && str[pos] <= 'Z')
        {
            result += str[pos];
        }
        else
        {
            if(str[pos] == '(')
            {
                pos++;
                result += solve();
            }
            else if(str[pos] == ')')
            {
                while(!stk.empty())
                {
                    result += stk.top();
                    stk.pop();
                }
                return result;
            }
            else if(str[pos] == '*' || str[pos] == '/')
            {
                if(!stk.empty() && (stk.top() == '*' || stk.top() == '/'))
                {
                    result += stk.top();
                    stk.pop();
                    stk.push(str[pos]);
                }
                else
                {
                    stk.push(str[pos]);
                }
            }
            else if(str[pos] == '+' || str[pos] == '-')
            {
                if(stk.empty())
                {
                    stk.push(str[pos]);
                }
                else if(stk.top() != '*' || stk.top() != '/')
                {
                    while(!stk.empty())
                    {
                        result += stk.top();
                        stk.pop();
                    }
                    stk.push(str[pos]);
                }
            }
        }
        pos++;
    }
    
    while(!stk.empty())
    {
        result += stk.top();
        stk.pop();
    }
    
    return result;
}

int main()
{
    cin >> str;
    cout << solve();
}