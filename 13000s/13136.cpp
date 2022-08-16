#include <iostream>

using namespace std;

int main()
{
    long long n, m, c;
    long long x, y;
    cin >> n >> m >> c;
    
    x = n / c;
    if(n % c)
    {
        x++;
    }
    y = m / c;
    if(m % c)
    {
        y++;
    }
    long long result = x * y;
    cout << result;
}