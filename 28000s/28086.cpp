#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    long long a = 0, b = 0, result = 0;
    bool minus_a = false, minus_b = false;
    char ch;
    int pos = 0;
    cin >> str;

    if(str[0] == '-')
    {
        minus_a = true;
        pos++;
    }
    for(; pos < str.length(); pos++)
    {
        if('0' <= str[pos] && str[pos] <= '9')
        {
            a *= 8;
            a += str[pos] - '0';
        }
        else
        {
            ch = str[pos];
            pos++;
            break;
        }
    }
    if(str[pos] == '-')
    {
        minus_b = true;
        pos++;
    }
    for(; pos < str.length(); pos++)
    {
        if('0' <= str[pos] && str[pos] <= '9')
        {
            b *= 8;
            b += str[pos] - '0';
        }
    }
    if(minus_a)
    {
        a *= -1;
    }
    if(minus_b)
    {
        b *= -1;
    }

    if(ch == '/' && b == 0)
    {
        cout << "invalid";
        return 0;
    }

    else
    {
        if(ch == '+')
        {
            result = a+b;
        }
        else if(ch == '-')
        {
            result = a-b;
        }
        else if(ch == '*')
        {
            result = a*b;
        }
        else if(ch == '/')
        {
            result = a/b;
            long long r = a % b;
            if(r != 0 && (a > 0) != (b > 0))
            {
                result--;
            }
        }
    }

    if(result < 0)
    {
        cout << "-";
    }
    cout << oct << abs(result);
}