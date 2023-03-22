#include <iostream>

using namespace std;

int main()
{
    int a, b, c = 0;
    cin >> a >> b;

    while(a >= 2 && b >= 1)
    {
        a -= 2;
        b -= 1;
        c++;
    }

    cout << c;
}