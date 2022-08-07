#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string str;
    cin >> str;

    stack <int> num_stack;

    for(int i = 0; i < str.length(); i++)
    {
        char temp_char = str[i];
        if('0' <= temp_char && temp_char <= '9')
        {
            num_stack.push(temp_char - '0');
        }
        else
        {
            string curr_operator = str.substr(i, 1);

            int a = num_stack.top();
            num_stack.pop();
            int b = num_stack.top();
            num_stack.pop();
            
            if(curr_operator == "+")
            {
                num_stack.push(b + a);
            }
            else if(curr_operator == "-")
            {
                num_stack.push(b - a);
            }
            else if(curr_operator == "*")
            {
                num_stack.push(b * a);
            }
            else if(curr_operator == "/")
            {
                num_stack.push(b / a);
            }
        }
    }

    cout << num_stack.top();
}