#include <iostream>

using namespace std;

int main()
{
    long long k, n;
    cin >> k >> n;

    if(n == 1)
    {
        cout << -1;
        return 0;
    }

    long long result = k*n / (n-1);
    if(k*n % (n-1))
    {
        result++;
    }

    cout << result;
}