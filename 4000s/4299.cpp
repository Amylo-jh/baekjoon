#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if(a < b)
    {
        cout << -1;
        return 0;
    }

    if((a+b)%2 == 1)
    {
        cout << -1;
        return 0;
    }

    cout << (a+b)/2 << " " << a - (a+b)/2;
}