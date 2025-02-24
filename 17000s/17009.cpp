#include <iostream>

using namespace std;

int main()
{
    int sa = 0, sb = 0;
    int a3, a2, a1, b3, b2, b1;
    cin >> a3 >> a2 >> a1 >> b3 >> b2 >> b1;
    sa = a3 * 3 + a2 * 2 + a1;
    sb = b3 * 3 + b2 * 2 + b1;

    if(sa > sb)
    {
        cout << "A";
    }
    else if(sa < sb)
    {
        cout << "B";
    }
    else
    {
        cout << "T";
    }
}