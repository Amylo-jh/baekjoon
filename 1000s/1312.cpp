#include <iostream>

using namespace std;

int main()
{
    int a, b, c, n;
    cin >> a >> b >> n;
    for (int i = 0; i < n; i++)
    {
        c = a % b;
        a = c * 10;
    }
    cout << a / b;
}