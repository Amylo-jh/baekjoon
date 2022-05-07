#include <iostream>

using namespace std;

int main()
{
    long long a = 0, b = 1, c = 0;

    int n = 0;

    cin >> n;

    for(int i = 0; i < n-1; i++)
    {
        c = a + b;
        a = b;
        b = c;

        a = a % 1000000007;
        b = b % 1000000007;
        c = c % 1000000007;
    }
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    cout << c;
}