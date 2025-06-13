#include <iostream>

using namespace std;

int main()
{
    long long a, b, sum = 0;
    cin >> a >> b;
    a = (a+1)/2*2;
    a = max(4LL, a);
    b = b/2*2;

    if(a > b)
    {
        cout << 0;
        return 0;
    }
    long long count = (b - a)/2+1;
    sum = (b+a)/2 * count;

    cout << sum;
}