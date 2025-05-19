#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long up, down, a, b, g, l;
    cin >> up >> down;
    for(int i = 1; i < n; i++)
    {
        cin >> a >> b;
        g = gcd(down, b);
        l = lcm(down, b);

        up = up * (b/g);
        a = a * (down/g);
        down = l;
        b = l;

        up = gcd(up, a);
        g = gcd(up, down);
        up /= g;
        down /= g;
    }
    g = gcd(up, down);
    up /= g;
    down /= g;

    cout << up << " " << down;
}