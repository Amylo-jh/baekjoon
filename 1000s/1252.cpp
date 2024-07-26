#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    vector <bool> v1(81, false), v2(81, false), answer(81, false);
    
    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] == '1')
        {
            v1[i] = true;
        }
    }
    for(int i = 0; i < str2.size(); i++)
    {
        if(str2[i] == '1')
        {
            v2[i] = true;
        }
    }

    bool carry = false;
    for(int i = 0; i < 81; i++)
    {
        if(v1[i] && v2[i])
        {
            if(carry)
            {
                answer[i] = true;
            }
            else
            {
                carry = true;
            }
        }
        else if(v1[i] || v2[i])
        {
            if(carry)
            {
                carry = true;
            }
            else
            {
                answer[i] = true;
            }
        }
        else
        {
            if(carry)
            {
                answer[i] = true;
                carry = false;
            }
        }
    }

    string answer_str = "";
    for(int i = 80; i >= 0; i--)
    {
        if(answer[i])
        {
            answer_str += "1";
        }
        else
        {
            answer_str += "0";
        }
    }

    bool flag = true;
    for(int i = 0; i < 81; i++)
    {
        if(flag && answer_str[i] == '0')
        {
            continue;
        }
        if(answer_str[i] == '1' || !flag)
        {
            flag = false;
            cout << answer_str[i];
        }
    }

    if(flag)
    {
        cout << "0";
    }
}