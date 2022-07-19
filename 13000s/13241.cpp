#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << a * b / gcd(a, b);
}