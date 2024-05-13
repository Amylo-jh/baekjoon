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

        int strnum = 0;
        strnum += (str[0] - 'A') *26*26;
        strnum += (str[1] - 'A') *26;
        strnum += (str[2] - 'A');

        int num = 0;
        num += (str[4] - '0') * 1000;
        num += (str[5] - '0') * 100;
        num += (str[6] - '0') * 10;
        num += (str[7] - '0');

        if(abs(strnum - num)  <= 100)
        {
            cout << "nice";
        }
        else
        {
            cout << "not nice";
        }
        cout << "\n";
    }
}