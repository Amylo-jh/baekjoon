#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int a, b;
        cin >> a >> b;
        int lcm = a*b;

        if(a < b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        while(b != 0)
        {
            int n = a % b;
            a = b;
            b = n;
        }

        cout << lcm/a << "\n";;
    }
}