#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string str;
        cin >> str;
        int idx = 0;
        bool bl = true;
        bool exist = false;

        if(str[0] == '!')
        {
            exist = true;
            while(str[idx] == '!')
            {
                bl = !bl;
                idx++;
            }
        }
        int num;
        if(str[idx] == '0')
        {
            num = 0;
        }
        else
        {
            num = 1;
        }
        idx++;

        bool factorial = false;
        if(str.length() != idx)
        {
            factorial = true;
        }

        bool result;
        if(exist)
        {
            result = num | factorial;
            if(!bl)
            {
                result = !result;
            }
        }
        else
        {
            result = num | factorial;
        }

        cout << result << "\n";
    }
}