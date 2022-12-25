#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    bool flag = true;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] != str[str.length() - i - 1])
        {
            flag = false;
            break;
        }
    }

    if(flag)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}