#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int answer = 0;

    cin >> str;
    if(str[0] == '0')
    {
        if(str[1] == 'x')
        {
            for(int i = 2; i < str.length(); i++)
            {
                answer *= 16;
                if(str[i] >= '0' && str[i] <= '9')
                {
                    answer += str[i] - '0';
                }
                else
                {
                    answer += str[i] - 'a' + 10;
                }
            }
        }
        else
        {
            for(int i = 1; i < str.length(); i++)
            {
                answer *= 8;
                answer += str[i] - '0';
            }
        }
    }  
    else
    {
        answer = stoi(str);
    }

    cout << answer;
}