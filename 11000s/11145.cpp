#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    cin.ignore();

    while(tc--)
    {
        string str;
        string answer;
        getline(cin, str);
        bool flag = false;
        bool is_space = false;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == ' ')
            {
                if(answer == "")
                {
                    continue;
                }
                else
                {
                    is_space = true;
                }
            }
            else if('0' <= str[i] && str[i] <= '9' && !is_space)
            {
                answer += str[i];
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            int idx = 0;
            while(answer[idx] == '0')
            {
                idx++;
            }
            if(idx == answer.length())
            {
                cout << "0\n";
                continue;
            }
            for(int i = idx; i < answer.length(); i++)
            {
                cout << answer[i];
            }
            cout << "\n";
        }
        else
        {
            cout << "invalid input\n";
        }
    }
}