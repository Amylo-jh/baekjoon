#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int max_value = max(a, max(b, c));
    int sum = a + b + c;
    if(a + b + c - max_value <= max_value)
    {
        cout << (sum - max_value)*2 - 1;
    }
    else
    {
        cout << sum;
    }
}