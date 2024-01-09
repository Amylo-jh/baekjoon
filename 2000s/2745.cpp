#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string str;
    int b;
    cin >> str >> b;

    int decimal_num = 0;
    for(int i = str.length()-1; i >= 0; i--)
    {
        int power = str.length()-1 - i;
        int num = 0;
        if('A' <=str[i] && str[i] <= 'Z')
        {
            num = 10 + str[i] - 'A';
        }
        else
        {
            num = str[i] - '0';
        }

        decimal_num += num * pow(b, power);
    }

    cout << decimal_num;
}