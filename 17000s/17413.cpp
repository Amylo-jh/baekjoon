#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str, answer, tmp;
    bool flag = false;

    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if(flag)
        {
            tmp += str[i];
        }
        if(str[i] == '<')
        {
            reverse(tmp.begin(), tmp.end());
            answer += tmp;
            tmp = "";
            tmp += str[i];
            flag = true;
        }
        else if(str[i] == '>')
        {
            flag = false;
            answer += tmp;
            tmp = "";
        }
        else if(!flag && str[i] != ' ')
        {
            tmp += str[i];
        }
        else if(!flag && str[i] == ' ')
        {
            reverse(tmp.begin(), tmp.end());
            answer += tmp;
            answer += ' ';
            tmp = "";
        }
    }
    reverse(tmp.begin(), tmp.end());
    answer += tmp;
    cout << answer;
}