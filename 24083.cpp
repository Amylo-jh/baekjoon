#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    a = (a + b) % 12;

    if(a == 0)
    {
        a = 12;
    }
    
    cout << a;
}