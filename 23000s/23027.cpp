#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    bool a = false, b = false, c = false, none = true;
    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'A')
        {
            a = true;
        }
        if(str[i] == 'B')
        {
            b = true;
        }
        if(str[i] == 'C')
        {
            c = true;
        }
    }

    if(a)
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == 'B' || str[i] == 'C' || str[i] == 'D' || str[i] == 'F')
            {
                str[i] = 'A';
            }
        }
    }
    else if(b)
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == 'C' || str[i] == 'D' || str[i] == 'F')
            {
                str[i] = 'B';
            }
        }
    }
    else if(c)
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == 'D' || str[i] == 'F')
            {
                str[i] = 'C';
            }
        }
    }
    else
    {
        for(int i = 0; i < str.length(); i++)
        {
            str[i] = 'A';
        }
    }

    cout << str;
}