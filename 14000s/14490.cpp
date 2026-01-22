#include <iostream>
#include <string>
#include <numeric>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int a = 0, b = 0, p = 0;
    for (p = 0; p < str.length(); p++)
    {
        if (str[p] == ':')
        {
            p++;
            break;
        }
        a *= 10;
        a += str[p] - '0';
    }
    for (; p < str.length(); p++)
    {
        b *= 10;
        b += str[p] - '0';
    }

    int gcd_num = gcd(a, b);
    cout << a / gcd_num << ":" << b / gcd_num;
}