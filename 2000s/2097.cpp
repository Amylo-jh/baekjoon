#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long a = 1;
    long long b = 1;

    while(a*b < n)
    {
        if(a == b)
        {
            a++;
        }
        else
        {
            b++;
        }
    }

    a--;
    b--;
    cout << max(4LL, a+a+b+b);
}