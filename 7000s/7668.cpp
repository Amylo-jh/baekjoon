#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while(1)
    {
        cin >> str;
        if(str == "end")
        {
            break;
        }

        int num = 0;
        for(int i = 0; i < str.length(); i++)
        {
            num *= 62;
            char ch = str[i];
            if('0' <= ch && ch <= '9')
            {
                num += ch-'0';
            }
            else if('A' <= ch && ch <= 'Z')
            {
                num += ch-'A' + 10;
            }
            else if('a' <= ch && ch <= 'z')
            {
                num += ch-'a' + 36;
            }

            num %= 61;
        }

        if(num)
        {
            cout << "no\n";
        }
        else
        {
            cout << "yes\n";
        }
    }
}