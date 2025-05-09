#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a = 0, b = 0;
    for(long long i = 2; i <= n; i *= 2)
    {
        a += n/i;
    }
    for(long long i = 5; i <= n; i *= 5)
    {
        b += n/i;
    }
    cout << min(a, b);
}