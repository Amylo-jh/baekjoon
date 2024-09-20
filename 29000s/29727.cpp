#include <iostream>

using namespace std;

int main()
{
    long long n, xa, xb, ya, yb;
    cin >> n >> xa >> ya >> xb >> yb;

    long long sum = 0;
    sum = (n+1)*n/2 * (n+1)*n/2;

    if(xa == xb)
    {
        xa = max(-1LL, xa);
        xa = min(n, xa);
        xb = max(-1LL, xb);
        xb = min(n, xb);
        ya = max(-1LL, ya);
        ya = min(n, ya);
        yb = max(-1LL, yb);
        yb = min(n, yb);

        long long diff = abs(ya - yb);
        sum += diff*(diff-1)/2 * (n+1);
    }
    
    if(ya == yb)
    {
        xa = max(-1LL, xa);
        xa = min(n, xa);
        xb = max(-1LL, xb);
        xb = min(n, xb);
        ya = max(-1LL, ya);
        ya = min(n, ya);
        yb = max(-1LL, yb);
        yb = min(n, yb);

        long long diff = abs(xa - xb);
        sum += diff*(diff-1)/2 * (n+1);
    }

    cout << sum;
}