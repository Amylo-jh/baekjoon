#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int money;
        cin >> money;

        int q = 0;
        int d = 0;
        int n = 0;
        int p = 0;

        q = money / 25;
        money %= 25;
        d = money / 10;
        money %= 10;
        n = money / 5;
        money %= 5;
        p = money;

        cout << q << " " << d << " " << n << " " << p << "\n";
    }
}