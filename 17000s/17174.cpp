#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int sum = n;
    int k = n / m;

    while(k)
    {
        sum += k;
        k = k / m;
    }

    cout << sum;
}