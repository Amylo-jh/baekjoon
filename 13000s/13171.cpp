#include <iostream>

using namespace std;

int main()
{
    unsigned long long r = 1000000007;
    unsigned long long one = 1;
    unsigned long long answer = 1;
    unsigned long long a, x;
    cin >> a >> x;

    a %= r;
    while (x)
    {
        if(x & one)
        {
            answer = (answer * a) % r;
        }
        a = a*a % r;
        x /= 2;
    }

    cout << answer;
}