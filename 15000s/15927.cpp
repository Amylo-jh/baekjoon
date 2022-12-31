#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int start_pos = 0;
    int end_pos = str.length() - 1;

    bool flag = true;
    for(int i = 0; i < str.length() / 2; i++)
    {
        if(str[i] != str[str.length() - i - 1])
        {
            flag = false;
            break;
        }
    }

    if(flag)
    {
        flag = true;
        for(int i = 1; i < str.length(); i++)
        {
            if(str[i] != str[str.length() - i])
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            cout << -1;
        }
        else
        {
            cout << str.length() - 1;
        }
    }
    else
    {
        cout << str.length();
    }
}