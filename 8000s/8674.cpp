#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    if(a % 2 && b % 2)
    {
        cout << min(a, b);
    }
    else
    {
        cout << 0;
    }
}