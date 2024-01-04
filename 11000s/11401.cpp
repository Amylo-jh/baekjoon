#include <iostream>
#include <vector>

using namespace std;

int n, k, p = 1000000007;

int main()
{
    cin >> n >> k;
    long long a = 1, b = 1;

    for(int i = 1; i <= n; i++)
    {
        a *= i;
        a %= p;
    }

    for(int i = 1; i <= k; i++)
    {
        b *= i;
        b %= p;
    }
    for(int i = 1; i <= n-k; i++)
    {
        b *= i;
        b %= p;
    }

    long long result = 1;
    long long p2 = p-2;
    while(p2)
    {
        if(p2 & 1)
        {
            result = result* b;
        }
        b *= b;
        b %= p;
        p2 /= 2;
        result %= p;
    }

    cout << a * result % p;
}