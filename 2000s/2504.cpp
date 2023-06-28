#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    stack <char> stk;
    int temp = 1;
    int answer = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(')
        {
            stk.push('(');
            temp *= 2;
        }
        else if(str[i] == ')')
        {
            if(!stk.empty() && stk.top() == '(')
            {
                stk.pop();
                if(str[i-1] == '(')
                {
                    answer += temp;
                }
                temp /= 2;
            }
            else
            {
                answer = 0;
                break;
            }
        }
        else if(str[i] == '[')
        {
            stk.push('[');
            temp *= 3;
        }
        else if(str[i] == ']')
        {
            if(!stk.empty() && stk.top() == '[')
            {
                stk.pop();
                if(str[i-1] == '[')
                {
                    answer += temp;
                }
                temp /= 3;
            }
            else
            {
                answer = 0;
                break;
            }
        }
    }

    if(stk.empty())
    {
        cout << answer;
    }
    else
    {
        cout << 0;
    }
}