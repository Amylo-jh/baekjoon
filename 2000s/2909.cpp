#include <iostream>

using namespace std;

int main()
{
    long long c, k;
    cin >> c >> k;

    if(k == 0)
    {
        cout << c;
        return 0;
    }
    
    for(int i = 1; i < k; i++)
    {
        c /= 10;
    }
    if(c % 10 < 5)
    {
        c -= c % 10;
    }
    else
    {
        c += (10 - c % 10);
    }
    for(int i = 1; i < k; i++)
    {
        c *= 10;
    }
    cout << c;
}