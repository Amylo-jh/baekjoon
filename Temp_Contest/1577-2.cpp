#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    string str = "";
    cin >> a >> b;

    if(pow(2, int(log2(b))) != b)
    {
        cout << -1;
        return 0;
    }

    while(a != 1 || b != 1)
    {
        if(a < b)
        {
            b /= 2;
            str += "K";
        }
        else
        {
            a -= b;
            str += "G";
        }
    }
    str += "G";
    reverse(str.begin(), str.end());
    cout << str;
}