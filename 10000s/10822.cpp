#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int sum = 0, tmp = 0;
    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ',')
        {
            sum += tmp;
            tmp = 0;
        }
        else
        {
            tmp *= 10;
            tmp += str[i] - '0';
        }
    }
    sum += tmp;
    cout << sum;
}