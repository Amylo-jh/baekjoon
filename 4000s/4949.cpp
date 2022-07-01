#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string str;
    while(getline(cin, str))
    {
        bool flag = true;
        if(str == ".")
        {
            break;
        }

        int num = str.length();
        stack <char> stk;

        for(int i = 0; i < num; i++)
        {
            if(str[i] == '[' || str[i] == ']' || str[i] == '(' || str[i] == ')')
            {
                if(str[i] == '[' || str[i] == '(')
                {
                    stk.push(str[i]);
                }
                else if(str[i] == ']' || str[i] == ')')
                {
                    if(stk.empty())
                    {
                        cout << "no" << endl;
                        flag = false;
                        break;
                    }
                    else
                    {
                        if( (str[i] == ']' && stk.top() == '[') || (str[i] == ')' && stk.top() == '(') )
                        {
                           stk.pop();
                        }
                        else
                        {
                            cout << "no" << endl;
                            flag = false;
                            break;
                        }
                    }
                }
            }
        }

        if(stk.empty() && flag)
        {
            cout << "yes" << endl;
        }
        else if(flag)
        {
            cout << "no" << endl;
        }
    }
}