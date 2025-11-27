#include <iostream>

using namespace std;

int main()
{
    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    if(0 < ((n*3) - m))
    {
        cout << ((n*3-m) * a) + b;
    }
    else
    {
        cout << 0;
    }
}