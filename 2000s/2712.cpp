#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    cout << fixed;
    cout.precision(4);
    int tc;
    cin >> tc;
    while(tc--)
    {
        double num;
        string str;
        cin >> num >> str;

        if(str == "kg")
        {
            num = num*2.2046;
            str = "lb";
        }
        else if(str == "lb")
        {
            num = num*0.4536;
            str = "kg";
        }
        else if(str == "l")
        {
            num = num*0.2642;
            str = "g";
        }
        else if(str == "g")
        {
            num = num*3.7854;
            str = "l";
        }

        num += 0.00000005;
        num *= 10000;
        num = round(num);
        num /= 10000;
        cout << num << " " << str << "\n";
    }
}