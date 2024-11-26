#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long p = 0, b = 0;
    for(int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        p += x;
    }
    for(int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        b += x;
    }

    cout << b << " " << p;
}