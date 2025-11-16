#include <iostream>

using namespace std;

int main()
{
    int n, m, a, b, t, pos, sum = 0;
    cin >> n >> m >> t;
    a = 1, b = m;
    while(t--)
    {
        cin >> pos;
        if(pos < a)
        {
            sum += a - pos;
            a = pos;
            b = a+(m-1);
        }
        else if(b < pos)
        {
            sum += pos - b;
            b = pos;
            a = b-(m-1);
        }
    }
    cout << sum;
}