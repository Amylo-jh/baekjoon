#include <iostream>

using namespace std;

int main()
{
    long long result = 1;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    for(int i = 1; i <= n; i++)
    {
        result *= i;
    }
    for(int i = 1; i <= a; i++)
    {
        result /= i;
    }
    for(int i = 1; i <= b; i++)
    {
        result /= i;
    }
    for(int i = 1; i <= c; i++)
    {
        result /= i;
    }

    cout << result;
}