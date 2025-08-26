#include <iostream>
#include <string>

#define TO_UPPER(c) (('a' <= (c) && (c) <= 'z') ? ((c) - ('a' - 'A')) : (c))

using namespace std;

int main()
{
    while(1)
    {
        string str;
        getline(cin, str);
        if(str == "*")
        {
            break;
        }
        
        char ch = str[0];
        ch = TO_UPPER(ch);
        if(ch >= 'a')
        {
            ch -= 'a' - 'A';
        }

        bool flag = true;
        for(int i = 1; i < str.length(); i++)
        {
            if(str[i-1] == ' ')
            {
                if(ch != TO_UPPER(str[i]))
                {
                    cout << "N\n";
                    flag = false;
                    break;
                }
            }
        }

        if(flag)
        {
            cout << "Y\n";
        }
    }
}