#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 2;
    while(sum-1 < n)
    {
        n -= sum-1;
        sum++;
    }

    cout << sum-n << " " << n;
}