#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str, newstr;
    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        newstr += str[i];
        if(str[i] == '-')
        {
            i++;
            newstr += str[i];

            while(i+1 < str.length() && str[i+1] == '0')
            {
                newstr += '+';
                newstr += str[++i];
            }
            if(i+1 < str.length() && '1' <= str[i+1] && str[i+1] <= '9')
            {
                newstr += '+';
            }
        }
    }
    cout << newstr;
}