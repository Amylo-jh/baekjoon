#include <iostream>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    n = n - m;

    if(n < 0)
    {
        n = n * -1;
    }

    cout << n;
}