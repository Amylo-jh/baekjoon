#include <iostream>

using namespace std;

int main()
{
    int l, r, b, diff = 0;
    cin >> l >> r >> b;
    if (l < r)
    {
        int diff = r - l;
        l += min(diff, b);
        b -= min(diff, b);
        r = l;
    }
    if (r < l)
    {
        int diff = l - r;
        r += min(diff, b);
        b -= min(diff, b);
        l = r;
    }
    if(b % 2)
    {
        b--;
    }
    cout << l + r + b;
}