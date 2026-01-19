#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, h, s, s1, s2;
    cin >> a >> b >> h;
    if(a > b)
    {
        swap(a, b);
    }
    if(a == b)
    {
        cout << -1;
        return 0;
    }
    s2 = sqrt((h*h) + (b-a)*(b-a));
    s = s2/(b-a) * b;
    cout.precision(30);
    cout << s*s*M_PI - (s*(a/b))*(s*(a/b))*M_PI;
}