#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    n *= 2;

    long long sum = 0;
    long long divider = 1;
    int count = 0;

    while(divider*2 <= n)
    {
        divider *= 2;
    }

    while(divider > 1)
    {
        count = n / divider - count;
        sum += count;
        count = n / divider;
        sum *= 2;
        divider /= 2;
    }

    cout << sum;
}