#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while(1)
    {
        cin >> str;
        if(str == "#")
        {
            break;
        }

        long long answer = 0;
        for(int i = 0; i < str.length(); i++)
        {
            answer *= 8;
            if(str[i] == '-')
            {
                answer += 0;
            }
            else if(str[i] == '\\')
            {
                answer += 1;
            }
            else if(str[i] == '(')
            {
                answer += 2;
            }
            else if(str[i] == '@')
            {
                answer += 3;
            }
            else if(str[i] == '?')
            {
                answer += 4;
            }
            else if(str[i] == '>')
            {
                answer += 5;
            }
            else if(str[i] == '&')
            {
                answer += 6;
            }
            else if(str[i] == '%')
            {
                answer += 7;
            }
            else if(str[i] == '/')
            {
                answer += -1;
            }
        }
        cout << answer << "\n";
    }
}