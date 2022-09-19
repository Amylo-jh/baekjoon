#include <iostream>

using namespace std;

int main()
{
    int n, m;
    int a, b, c, d, q, r;
    cin >> n >> m;

    a = 100 - n;
    b = 100 - m;
    d = a * b;
    q = d / 100;
    r = d % 100;
    c = 100 - (a + b);

    cout << a << " " << b << " " << c << " " << d << " " << q << " " << r << "\n";
    c += q;
    cout << c << " " << r;

    
}