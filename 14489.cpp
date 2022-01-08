#include <iostream>

using namespace std;

int main()
{
    long long a, b, chicken;

    cin >> a >> b >> chicken;

    if(2* chicken <= a + b)
    {
        cout << a+b - 2*chicken;
    }
    else
    {
        cout << a + b;
    }
}