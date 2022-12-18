#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b;
    string str;
    cin >> a >> str;

    a = 0; //security
    b = 0; //bigdata

    int idx = 0;

    while(idx < str.length())
    {
        if(str[idx] == 's')
        {
            a++;
            idx += 8;
        }
        else
        {
            b++;
            idx += 7;
        }
    }

    if(a > b)
    {
        cout << "security!";
    }
    else if(a < b)
    {
        cout << "bigdata?";
    }
    else
    {
        cout << "bigdata? security!";
    }
}