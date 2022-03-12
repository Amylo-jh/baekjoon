#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    
    string num;
    int pos = 9999999;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'x')
        {
            pos = i;
        }
    }

    if(pos == 9999999)
    {
        cout << "0";
        return 0;
    }

    if(pos == 0)
    {
        cout << "1";
        return 0;
    }

    num = str.substr(0, pos);
    
    if(num == "-")
    {
        cout << "-1";
        return 0;
    }

    cout << num;
}