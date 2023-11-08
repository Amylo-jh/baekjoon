#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int numerator = a*d + c*b;
    int denominator = b*d;
    int gcd_num = gcd(numerator, denominator);
    numerator /= gcd_num;
    denominator /= gcd_num;
    cout << numerator << " " << denominator;
}